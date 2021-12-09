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

    // Print the voxel-size to cout
    std::cout << "VoxelSize=" << voxelSize << std::endl;

    // Create a transform using this voxel-size.
    openvdb::math::Transform::Ptr transform =
        openvdb::math::Transform::createLinearTransform(voxelSize);

    // Create a PointDataGrid containing these four points and using the
    // transform given. This function has two template parameters, (1) the codec
    // to use for storing the position, (2) the grid we want to create
    // (ie a PointDataGrid).
    // We use no compression here for the positions.
    openvdb::points::PointDataGrid::Ptr grid =
        openvdb::points::createPointDataGrid<openvdb::points::NullCodec,
                        openvdb::points::PointDataGrid>(positions, *transform);

    // Set the name of the grid
    grid->setName("Points");

    // Create a VDB file object and write out the grid.
    openvdb::io::File("mypoints.vdb").write({grid});

    // Create a new VDB file object for reading.
    openvdb::io::File newFile("mypoints.vdb");

    // Open the file. This reads the file header, but not any grids.
    newFile.open();

    // Read the grid by name.
    openvdb::GridBase::Ptr baseGrid = newFile.readGrid("Points");
    newFile.close();

    // From the example above, "Points" is known to be a PointDataGrid,
    // so cast the generic grid pointer to a PointDataGrid pointer.
    grid = openvdb::gridPtrCast<openvdb::points::PointDataGrid>(baseGrid);

    openvdb::Index64 count = openvdb::points::pointCount(grid->tree());
    std::cout << "PointCount=" << count << std::endl;

    // Iterate over all the leaf nodes in the grid.
    for (auto leafIter = grid->tree().cbeginLeaf(); leafIter; ++leafIter) {

        // Verify the leaf origin.
        std::cout << "Leaf" << leafIter->origin() << std::endl;

        // Extract the position attribute from the leaf by name (P is position).
        const openvdb::points::AttributeArray& array =
            leafIter->constAttributeArray("P");

        // Create a read-only AttributeHandle. Position always uses Vec3f.
        openvdb::points::AttributeHandle<openvdb::Vec3f> positionHandle(array);

        // Iterate over the point indices in the leaf.
        for (auto indexIter = leafIter->beginIndexOn(); indexIter; ++indexIter) {

            // Extract the voxel-space position of the point.
            openvdb::Vec3f voxelPosition = positionHandle.get(*indexIter);

            // Extract the world-space position of the voxel.
            const openvdb::Vec3d xyz = indexIter.getCoord().asVec3d();

            // Compute the world-space position of the point.
            openvdb::Vec3f worldPosition =
                grid->transform().indexToWorld(voxelPosition + xyz);

            // Verify the index and world-space position of the point
            std::cout << "* PointIndex=[" << *indexIter << "] ";
            std::cout << "WorldPosition=" << worldPosition << std::endl;
        }
    }
}