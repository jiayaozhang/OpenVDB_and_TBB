#include <openvdb/openvdb.h>

// Define a local function that retrieves a and b values from a CombineArgs
// struct and then sets the result member to the maximum of a and b.
struct Local
{
    static inline void max(openvdb::CombineArgs<float> &args)
    {
        if (args.b() > args.a())
        {
            // Transfer the B value and its active state.
            args.setResult(args.b());
            args.setResultIsActive(args.bIsActive());
        }
        else
        {
            // Preserve the A value and its active state.
            args.setResult(args.a());
            args.setResultIsActive(args.aIsActive());
        }
    }
};

int main()
{
    openvdb::initialize();

    openvdb::FloatGrid::Ptr
        aGrid = openvdb::FloatGrid::create(),
        bGrid = openvdb::FloatGrid::create();

    aGrid->tree().combineExtended(bGrid->tree(), Local::max);
}