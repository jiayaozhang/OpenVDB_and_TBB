#include <openvdb/openvdb.h>
#include <openvdb/tools/Interpolation.h>

int main()
{
    openvdb::initialize();

    using GridType = openvdb::FloatGrid;

    const GridType grid;

    // Choose fractional coordinates in index space.
    const openvdb::Vec3R ijk(10.5, -100.2, 50.3);

#if 1
    // Compute the value of the grid at ijk via nearest-neighbor (zero-order)
    // interpolation.
    GridType::ValueType v0 = openvdb::tools::PointSampler::sample(grid.tree(), ijk);

    // Compute the value via trilinear (first-order) interpolation.
    GridType::ValueType v1 = openvdb::tools::BoxSampler::sample(grid.tree(), ijk);

    // Compute the value via triquadratic (second-order) interpolation.
    GridType::ValueType v2 = openvdb::tools::QuadraticSampler::sample(grid.tree(), ijk);

#else
    GridType::ConstAccessor accessor = grid.getConstAccessor();

    GridType::ValueType v0 = openvdb::tools::PointSampler::sample(accessor, ijk);
    GridType::ValueType v1 = openvdb::tools::BoxSampler::sample(accessor, ijk);
    GridType::ValueType v2 = openvdb::tools::QuadraticSampler::sample(accessor, ijk);
#endif
}