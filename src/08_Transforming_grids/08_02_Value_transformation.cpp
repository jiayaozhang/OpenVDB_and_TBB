#include <openvdb/openvdb.h>
#include <openvdb/tools/ValueTransformer.h>

// Define a local function that doubles the value to which the given
// value iterator points.
struct Local
{
    static inline void op(const openvdb::FloatGrid::ValueAllIter &iter)
    {
        iter.setValue(*iter * 2);
    }
};

int main()
{
    openvdb::initialize();

    openvdb::FloatGrid::Ptr grid = openvdb::FloatGrid::create();

    // Apply the function to all values.
    openvdb::tools::foreach (grid->beginValueAll(), Local::op);
}