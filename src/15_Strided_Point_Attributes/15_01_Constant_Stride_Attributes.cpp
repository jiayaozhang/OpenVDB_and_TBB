#include <openvdb/openvdb.h>
#include <openvdb/points/PointConversion.h>
#include <openvdb/points/PointCount.h>

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataGrid::Ptr points = openvdb::points::PointDataGrid::create();

    // Store 10 values per point in an attribute called samples.
    openvdb::Index stride(10);
    openvdb::points::appendAttribute(points->tree(), "samples",
                                     openvdb::points::TypedAttributeArray<float>::attributeType(), stride);

    // Iterate over leaf nodes.
    for (auto leafIter = points->tree().beginLeaf(); leafIter; ++leafIter)
    {
        // Create a read-write samples handle.
        openvdb::points::AttributeArray &array(
            leafIter->attributeArray("samples"));
        openvdb::points::AttributeWriteHandle<float> handle(array);

        // Iterate over the point indices in the leaf.
        for (auto indexIter = leafIter->beginIndexOn(); indexIter; ++indexIter)
        {
            // Use ascending sample values for each element in the strided array
            for (int i = 0; i < 10; i++)
            {
                handle.set(*indexIter, /*strideIndex=*/i, float(i));
            }
        }
    }
}