#include <iostream>
#include <openvdb/openvdb.h>

int main() {
    //initialize the openvdb. this must be called at least
    // once per program and may safely be called multiple times.
    openvdb::initialize();

    //create an empty floating-point grid with background value 0.
    openvdb::FloatGrid::Ptr grid = openvdb::FloatGrid::create();
    std::cout << "Testing random access: " << std::endl;

    //get an accessor for coordinate-based access to voxels
    openvdb::Coord xyz(1000, -20000000, 30000000);

    //set the voxel value at (1000, -20000000, 30000000) to 1.
    accessor.setValue(xyz, 1.0);

    //Reset the coordinate to those of a different voxel.
    xyz.reset(1000, -20000000, 30000000);

    //verify that the voxel value at (1000, -20000000, 30000000) is
    // the background value 0.
    std::cout << "grid" << xyz << " = " << access.getValue(xyz) << std::endl;

    //set the voxel value at (1000, -20000000, 30000000) to 2
    access.setValue(xyz, 2.0);

    //set the voxels at the two extremes of the available coordinate space.
    //for 32-bit signed coordinates there are (-2147483648, -2147483648, -2147483648)
    // and (2147483647, 2147483647, 2147483647).

    access.setValue(openvdb::Coord::min(), 3.0f);
    access.setValue(openvdb::Coord::max(), 4.0f);

    std::cout << "testing sequential access: " << std::endl;

    //print all active ("on") voxels by means of an iterator.
    for(openvdb::FloatGrid::ValueOnCIter iter = grid->cbeginValueOn(); iter; ++iter)
    {
        std::cout << "grid" << iter.getCoord() << "=" << *iter << std::endl;
    }



    return 0;
}