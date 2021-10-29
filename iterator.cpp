#include <openvdb/openvdb.h>

using GridType= openvdb::FloatGrid;
using TreeType = GridType::TreeType;
using RootType = TreeType::RootNodeType;   // level 3 RootNode
assert(RootType::LEVEL == 3);
using Int1Type = RootType::ChildNodeType;  // level 2 InternalNode
using Int2Type = Int1Type::ChildNodeType;  // level 1 InternalNode
using LeafType = TreeType::LeafNodeType;   // level 0 LeafNode
GridType::Ptr grid = ...;
for (TreeType::NodeIter iter = grid->tree().beginNode(); iter; ++iter) {
    switch (iter.getDepth()) {
    case 0: { RootType* node = nullptr; iter.getNode(node); if (node) ...; break; }
    case 1: { Int1Type* node = nullptr; iter.getNode(node); if (node) ...; break; }
    case 2: { Int2Type* node = nullptr; iter.getNode(node); if (node) ...; break; }
    case 3: { LeafType* node = nullptr; iter.getNode(node); if (node) ...; break; }
    }
}
 
