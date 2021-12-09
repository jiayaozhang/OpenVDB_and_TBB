#include <openvdb/openvdb.h>

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
    openvdb::FloatGrid::Ptr resultGrid = openvdb::FloatGrid::create();

    // Combine aGrid and bGrid and write the result into resultGrid.
    // The input grids are not modified.
    resultGrid->tree().combine2(aGrid->tree(), bGrid->tree(), Local::diff);
}