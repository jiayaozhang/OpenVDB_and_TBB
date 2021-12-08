#include <openvdb/openvdb.h>
#include <openvdb/tools/ValueTransformer.h>

// Define a local function that, given an iterator pointing to a vector value
// in an input grid, sets the corresponding tile or voxel in a scalar,
// floating-point output grid to the length of the vector.
struct Local
{
    static inline void op(
        const openvdb::Vec3SGrid::ValueOnCIter &iter,
        openvdb::FloatGrid::Accessor &accessor)
    {
        if (iter.isVoxelValue())
        { // set a single voxel
            accessor.setValue(iter.getCoord(), iter->length());
        }
        else
        { // fill an entire tile
            openvdb::CoordBBox bbox;
            iter.getBoundingBox(bbox);
            accessor.getTree()->fill(bbox, iter->length());
        }
    }
};

int main()
{
    openvdb::initialize();

    openvdb::Vec3SGrid::ConstPtr inGrid = openvdb::Vec3SGrid::create();

    // Create a scalar grid to hold the transformed values.
    openvdb::FloatGrid::Ptr outGrid = openvdb::FloatGrid::create();

    // Populate the output grid with transformed values.
    openvdb::tools::transformValues(inGrid->cbeginValueOn(), *outGrid, Local::op);
}