#include <openvdb/openvdb.h>
#include <openvdb/tools/Composite.h>

int main()
{
    openvdb::initialize();

    // Two grids of the same type
    openvdb::FloatGrid::Ptr 
        gridA = openvdb::FloatGrid::create(),
        gridB = openvdb::FloatGrid::create();

    // Save copies of the two grids; compositing operations always
    // modify the A grid and leave the B grid empty.
    openvdb::FloatGrid::ConstPtr
        copyOfGridA = gridA->deepCopy(),
        copyOfGridB = gridB->deepCopy();

    // At each voxel, compute a = max(a, b).
    openvdb::tools::compMax(*gridA, *gridB);

    // Restore the original grids.
    gridA = copyOfGridA->deepCopy();
    gridB = copyOfGridB->deepCopy();

    // At each voxel, compute a = min(a, b).
    openvdb::tools::compMin(*gridA, *gridB);

    // Restore the original grids.
    gridA = copyOfGridA->deepCopy();
    gridB = copyOfGridB->deepCopy();

    // At each voxel, compute a = a + b.
    openvdb::tools::compSum(*gridA, *gridB);

    // Restore the original grids.
    gridA = copyOfGridA->deepCopy();
    gridB = copyOfGridB->deepCopy();

    // At each voxel, compute a = a * b.
    openvdb::tools::compMul(*gridA, *gridB);
}