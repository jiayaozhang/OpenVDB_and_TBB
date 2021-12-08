#include <iostream>
#include <vector>
#include <openvdb/openvdb.h>
#include <openvdb/points/PointConversion.h>
#include <openvdb/points/PointCount.h>

int main()
{
    // Initialize grid types and point attributes types.
    openvdb::initialize();

    // Create a vector with four point positions.
    std::vector<openvdb::Vec3R> positions;
    positions.push_back(openvdb::Vec3R(0, 1, 0));
    positions.push_back(openvdb::Vec3R(1.5, 3.5, 1));
    positions.push_back(openvdb::Vec3R(-1, 6, -2));
    positions.push_back(openvdb::Vec3R(1.1, 1.25, 0.06));

    // Create a vector with four radii.
    std::vector<float> radius;
    radius.push_back(0.1);
    radius.push_back(0.15);
    radius.push_back(0.2);
    radius.push_back(0.5);

    // The VDB Point-Partioner is used when bucketing points and requires a
    // specific interface. For convenience, we use the PointAttributeVector
    // wrapper around an stl vector wrapper here, however it is also possible to
    // write one for a custom data structure in order to match the interface
    // required.
    openvdb::points::PointAttributeVector<openvdb::Vec3R> positionsWrapper(positions);

    // This method computes a voxel-size to match the number of
    // points / voxel requested. Although it won't be exact, it typically offers
    // a good balance of memory against performance.
    int pointsPerVoxel = 8;
    float voxelSize =
        openvdb::points::computeVoxelSize(positionsWrapper, pointsPerVoxel);

    // Create a transform using this voxel-size.
    openvdb::math::Transform::Ptr transform =
        openvdb::math::Transform::createLinearTransform(voxelSize);

    // Create a PointIndexGrid. This can be done automatically on creation of
    // the grid, however as this index grid is required for the position and
    // radius attributes, we create one we can use for both attribute creation.
    openvdb::tools::PointIndexGrid::Ptr pointIndexGrid =
        openvdb::tools::createPointIndexGrid<openvdb::tools::PointIndexGrid>(
            positionsWrapper, *transform);

    // Create a PointDataGrid containing these four points and using the point
    // index grid. This requires the positions wrapper.
    openvdb::points::PointDataGrid::Ptr grid =
        openvdb::points::createPointDataGrid<
            openvdb::points::NullCodec,
            openvdb::points::PointDataGrid>(*pointIndexGrid, positionsWrapper, *transform);

    // Append a "pscale" attribute to the grid to hold the radius.
    // This attribute storage uses a unit range codec to reduce the memory
    // storage requirements down from 4-bytes to just 1-byte per value. This is
    // only possible because accuracy of the radius is not that important to us
    // and the values are always within unit range (0.0 => 1.0).
    // Note that this attribute type is not registered by default so needs to be
    // explicitly registered.
    using Codec = openvdb::points::FixedPointCodec</*1-byte=*/false,
                                                   openvdb::points::UnitRange>;
    openvdb::points::TypedAttributeArray<float, Codec>::registerType();
    openvdb::NamePair radiusAttribute =
        openvdb::points::TypedAttributeArray<float, Codec>::attributeType();
    openvdb::points::appendAttribute(grid->tree(), "pscale", radiusAttribute);

    // Create a wrapper around the radius vector.
    openvdb::points::PointAttributeVector<float> radiusWrapper(radius);

    // Populate the "pscale" attribute on the points
    openvdb::points::populateAttribute<openvdb::points::PointDataTree,
                                       openvdb::tools::PointIndexTree, openvdb::points::PointAttributeVector<float>>(
        grid->tree(), pointIndexGrid->tree(), "pscale", radiusWrapper);

    // Set the name of the grid
    grid->setName("Points");

    // Iterate over all the leaf nodes in the grid.
    for (auto leafIter = grid->tree().cbeginLeaf(); leafIter; ++leafIter)
    {
        // Verify the leaf origin.
        std::cout << "Leaf" << leafIter->origin() << std::endl;

        // Extract the position attribute from the leaf by name (P is position).
        const openvdb::points::AttributeArray &positionArray =
            leafIter->constAttributeArray("P");

        // Extract the radius attribute from the leaf by name (pscale is radius).
        const openvdb::points::AttributeArray &radiusArray =
            leafIter->constAttributeArray("pscale");

        // Create read-only handles for position and radius.
        openvdb::points::AttributeHandle<openvdb::Vec3f> positionHandle(positionArray);
        openvdb::points::AttributeHandle<float> radiusHandle(radiusArray);

        // Iterate over the point indices in the leaf.
        for (auto indexIter = leafIter->beginIndexOn(); indexIter; ++indexIter)
        {
            // Extract the voxel-space position of the point.
            openvdb::Vec3f voxelPosition = positionHandle.get(*indexIter);

            // Extract the world-space position of the voxel.
            openvdb::Vec3d xyz = indexIter.getCoord().asVec3d();

            // Compute the world-space position of the point.
            openvdb::Vec3f worldPosition =
                grid->transform().indexToWorld(voxelPosition + xyz);

            // Extract the radius of the point.
            float radius = radiusHandle.get(*indexIter);

            // Verify the index, world-space position and radius of the point.
            std::cout << "* PointIndex=[" << *indexIter << "] ";
            std::cout << "WorldPosition=" << worldPosition << " ";
            std::cout << "Radius=" << radius << std::endl;
        }
    }
}