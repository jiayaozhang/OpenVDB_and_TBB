#include <openvdb/openvdb.h>
#include <openvdb/tools/ChangeBackground.h>

int main()
{
    openvdb::initialize();

    using GridType = openvdb::Vec3SGrid;
    using TreeType = GridType::TreeType;

    GridType::Ptr grid = GridType::create();

    // Iterate over all active values but don't allow them to be changed.
    for (GridType::ValueOnCIter iter = grid->cbeginValueOn(); iter.test(); ++iter)
    {
        const openvdb::Vec3f &value = *iter;

        // Print the coordinates of all voxels whose vector value has
        // a length greater than 10, and print the bounding box coordinates
        // of all tiles whose vector value length is greater than 10.
        if (value.length() > 10.0)
        {
            if (iter.isVoxelValue())
            {
                std::cout << iter.getCoord() << std::endl;
            }
            else
            {
                openvdb::CoordBBox bbox;
                iter.getBoundingBox(bbox);
                std::cout << bbox << std::endl;
            }
        }
    }

    // Iterate over and normalize all inactive values.
    for (GridType::ValueOffIter iter = grid->beginValueOff(); iter.test(); ++iter)
    {
        openvdb::Vec3f value = *iter;
        value.normalize();
        iter.setValue(value);
    }

    // Normalize the (inactive) background value as well.
    // openvdb::tools::changeBackground(grid->tree(), grid->background().unit());
}