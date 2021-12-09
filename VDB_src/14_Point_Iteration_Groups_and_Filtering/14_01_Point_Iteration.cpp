#include <openvdb/openvdb.h>
#include <openvdb/points/PointDataGrid.h>

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataTree pointTree;

    for (auto leafIter = pointTree.beginLeaf(); leafIter; ++leafIter)
    {
        const openvdb::points::AttributeArray &array =
            leafIter->constAttributeArray("name");
        openvdb::points::AttributeHandle<float> handle(array);

        // Iterate over active indices in the leaf.
        for (auto indexIter = leafIter->beginIndexOn(); indexIter; ++indexIter)
        {
            // Retrieve value
            float value = handle.get(*indexIter);
        }
    }
}