#include <openvdb/openvdb.h>

int main()
{
    openvdb::initialize();

    openvdb::Vec3SGrid::Ptr grid = openvdb::Vec3SGrid::create();

    grid->insertMeta("vector type", openvdb::StringMetadata("covariant (gradient)"));
    grid->insertMeta("radius", openvdb::FloatMetadata(50.0));
    grid->insertMeta("center", openvdb::Vec3SMetadata(openvdb::Vec3s(10, 15, 10)));

    // OK, overwrites existing value:
    grid->insertMeta("center", openvdb::Vec3SMetadata(openvdb::Vec3s(10.5, 15, 30)));

    // Error (throws openvdb::TypeError), can't overwrite a value of type Vec3S
    // with a value of type float:
    // grid->insertMeta("center", openvdb::FloatMetadata(0.0));

    grid->removeMeta("vector type");
    grid->removeMeta("center");
    grid->removeMeta("vector type"); // OK (no effect)
}