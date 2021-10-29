#include <openvdb/openvdb.h>
#include <openvdb/tools/Composite.h>

// Two grids of the same type containing level set volumes
openvdb::FloatGrid::Ptr gridA(...), gridB(...);

// Save copies of the two grids; CSG operations always modify
// the A grid and leave the B grid empty.
openvdb::FloatGrid::ConstPtr
    copyOfGridA = gridA->deepCopy(),
    copyOfGridB = gridB->deepCopy();

// Compute the union (A u B) of the two level sets.
openvdb::tools::csgUnion(*gridA, *gridB);

// Restore the original level sets.
gridA = copyOfGridA->deepCopy();
gridB = copyOfGridB->deepCopy();

// Compute the intersection (A n B) of the two level sets.
openvdb::tools::csgIntersection(*gridA, *gridB);

// Restore the original level sets.
gridA = copyOfGridA->deepCopy();
gridB = copyOfGridB->deepCopy();

// Compute the difference (A / B) of the two level sets.
openvdb::tools::csgDifference(*gridA, *gridB);