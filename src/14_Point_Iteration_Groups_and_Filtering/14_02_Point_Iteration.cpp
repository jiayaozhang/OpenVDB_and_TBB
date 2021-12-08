#include <openvdb/openvdb.h>
#include <openvdb/points/PointDataGrid.h>

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataTree pointTree;

    for (auto leafIter = pointTree.beginLeaf(); leafIter; ++leafIter)
    {
        openvdb::points::AttributeArray &array =
            leafIter->attributeArray("name");
        openvdb::points::AttributeWriteHandle<float> handle(array);

        // Iterate over active indices in the leaf.
        for (auto indexIter = leafIter->beginIndexOn(); indexIter; ++indexIter)
        {
            // Set value
            handle.set(*indexIter, 5.0f);
        }
    }
}