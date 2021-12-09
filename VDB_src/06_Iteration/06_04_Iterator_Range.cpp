#include <openvdb/openvdb.h>
#include <openvdb/tools/LevelSetSphere.h>
#include <tbb/parallel_for.h>
#include <tbb/atomic.h>
#include <cassert>
#include <iostream>

// Global active voxel counter, atomically updated from multiple threads
tbb::atomic<openvdb::Index64> activeLeafVoxelCount;

// Functor for use with tbb::parallel_for() that operates on a grid's leaf nodes
template <typename GridType>
struct LeafProcessor
{
    using TreeType = typename GridType::TreeType;
    using LeafNode = typename TreeType::LeafNodeType;
    // Define an IteratorRange that splits the iteration space of a leaf iterator.
    using IterRange = openvdb::tree::IteratorRange<typename TreeType::LeafCIter>;

    void operator()(IterRange &range) const
    {
        // Note: this code must be thread-safe.

        // Iterate over a subrange of the leaf iterator's iteration space.
        for (; range; ++range)
        {
            // Retrieve the leaf node to which the iterator is pointing.
            const LeafNode &leaf = *range.iterator();
            // Update the global counter.
            activeLeafVoxelCount.fetch_and_add(leaf.onVoxelCount());
        }
    }
};

int main()
{
    openvdb::initialize();

    // Generate a level set grid.
    openvdb::FloatGrid::Ptr grid =
        openvdb::tools::createLevelSetSphere<openvdb::FloatGrid>(
            /*radius=*/20.0, /*center=*/openvdb::Vec3f(1.5, 2, 3), /*voxel size=*/0.5);

    // Construct a functor for use with tbb::parallel_for()
    // that processes the leaf nodes of a FloatGrid.
    using FloatLeafProc = LeafProcessor<openvdb::FloatGrid>;
    FloatLeafProc proc;

    // Wrap a leaf iterator in an IteratorRange.
    FloatLeafProc::IterRange range(grid->tree().cbeginLeaf());
    // Iterate over leaf nodes in parallel.
    tbb::parallel_for(range, proc);

    std::cout << activeLeafVoxelCount << " active leaf voxels" << std::endl;

    // The computed voxel count should equal the grid's active voxel count,
    // since all of the active voxels in a level set grid are stored at the
    // leaf level (that is, there are no active tiles in a level set grid).
    assert(activeLeafVoxelCount == grid->activeVoxelCount());
}