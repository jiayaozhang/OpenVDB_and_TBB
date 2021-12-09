#include <openvdb/openvdb.h>

// Define a functor that computes f * a + (1 - f) * b  for pairs of
// floating-point values a and b.
struct Blend
{
    Blend(float f) : frac(f) {}
    inline void operator()(const float &a, const float &b, float &result) const
    {
        result = frac * a + (1.0 - frac) * b;
    }
    float frac;
};

int main()
{
    openvdb::initialize();

    openvdb::FloatGrid::Ptr
        aGrid = openvdb::FloatGrid::create(),
        bGrid = openvdb::FloatGrid::create();

    // Compute a = 0.25 * a + 0.75 * b for all corresponding voxels of
    // aGrid and bGrid.  Store the result in aGrid and empty bGrid.
    aGrid->tree().combine(bGrid->tree(), Blend(0.25));
}