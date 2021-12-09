#include <openvdb/openvdb.h>

// Define a local function that subtracts two floating-point values.
struct Local
{
    static inline void diff(const float &a, const float &b, float &result)
    {
        result = a - b;
    }
};

int main()
{
    openvdb::initialize();

    openvdb::FloatGrid::Ptr
        aGrid = openvdb::FloatGrid::create(),
        bGrid = openvdb::FloatGrid::create();

    // Compute the difference between corresponding voxels of aGrid and bGrid
    // and store the result in aGrid, leaving bGrid empty.
    aGrid->tree().combine(bGrid->tree(), Local::diff);
}