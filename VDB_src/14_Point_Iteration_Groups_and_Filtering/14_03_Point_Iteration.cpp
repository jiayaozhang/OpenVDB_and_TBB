#include <openvdb/openvdb.h>
#include <openvdb/points/PointDataGrid.h>
#include <tbb/tbb.h>

struct ReadValueOp
{
    explicit ReadValueOp(openvdb::Index64 index) : mIndex(index) {}

    void operator()(const openvdb::tree::LeafManager<
                    openvdb::points::PointDataTree>::LeafRange &range) const
    {
        for (auto leafIter = range.begin(); leafIter; ++leafIter)
        {
            for (auto indexIter = leafIter->beginIndexOn();
                 indexIter; ++indexIter)
            {
                const openvdb::points::AttributeArray &array =
                    leafIter->constAttributeArray(mIndex);
                openvdb::points::AttributeHandle<float> handle(array);

                float value = handle.get(*indexIter);
            }
        }
    }

    openvdb::Index64 mIndex;
};

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataTree pointTree;

    // Create a leaf iterator for the PointDataTree.
    auto leafIter = pointTree.cbeginLeaf();

    // Check that the tree has leaf nodes.
    if (!leafIter)
    {
        std::cerr << "No Leaf Nodes" << std::endl;
    }

    // Retrieve the index from the descriptor.
    auto descriptor = leafIter->attributeSet().descriptor();
    openvdb::Index64 index = descriptor.find("name");

    // Check that the attribute has been found.
    if (index == openvdb::points::AttributeSet::INVALID_POS)
    {
        std::cerr << "Invalid Attribute" << std::endl;
    }

    // Create a leaf manager for the points tree.
    openvdb::tree::LeafManager<openvdb::points::PointDataTree> leafManager(
        pointTree);

    // Create a new operator
    ReadValueOp op(index);

    // Evaluate in parallel
    tbb::parallel_for(leafManager.leafRange(), op);

    // Evaluate parallel operator in serial
    // tbb::parallel_for(leafManager.leafRange(/*grainsize=*/1000000), op);
}