#include <openvdb/openvdb.h>

int main()
{
    openvdb::initialize();

    using GridType = openvdb::FloatGrid;
    using TreeType = GridType::TreeType;

    GridType::Ptr grid = GridType::create();

    // Iterate over references to const LeafNodes.
    for (TreeType::LeafCIter iter = grid->tree().cbeginLeaf(); iter; ++iter)
    {
        const TreeType::LeafNodeType &leaf = *iter;
        // ...
    }
    // Iterate over references to non-const LeafNodes.
    for (TreeType::LeafIter iter = grid->tree().beginLeaf(); iter; ++iter)
    {
        TreeType::LeafNodeType &leaf = *iter;
        // ...
    }
    // Iterate over pointers to const LeafNodes.
    for (TreeType::LeafCIter iter = grid->tree().cbeginLeaf(); iter; ++iter)
    {
        const TreeType::LeafNodeType *leaf = iter.getLeaf();
        // ...
    }
    // Iterate over pointers to non-const LeafNodes.
    for (TreeType::LeafIter iter = grid->tree().beginLeaf(); iter; ++iter)
    {
        TreeType::LeafNodeType *leaf = iter.getLeaf();
        // ...
    }
}