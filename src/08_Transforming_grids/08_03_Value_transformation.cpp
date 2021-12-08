#include <openvdb/openvdb.h>
#include <openvdb/tools/ValueTransformer.h>

// Define a functor that multiplies the vector to which the given
// value iterator points by a fixed matrix.
struct MatMul
{
    openvdb::math::Mat3s M;
    MatMul(const openvdb::math::Mat3s &mat) : M(mat) {}
    inline void operator()(const openvdb::Vec3SGrid::ValueOnIter &iter) const
    {
        iter.setValue(M.transform(*iter));
    }
};

int main()
{
    openvdb::initialize();

    openvdb::Vec3SGrid::Ptr grid = openvdb::Vec3SGrid::create();

    // Construct the rotation matrix.
    openvdb::math::Mat3s rot45 =
        openvdb::math::rotation<openvdb::math::Mat3s>(openvdb::math::Y_AXIS, M_PI_4);

    // Apply the functor to all active values.
    openvdb::tools::foreach (grid->beginValueOn(), MatMul(rot45));
}