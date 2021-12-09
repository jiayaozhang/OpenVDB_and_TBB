#include <openvdb/openvdb.h>
#include <openvdb/tools/Interpolation.h>

int main()
{
    openvdb::initialize();

    using GridType = openvdb::FloatGrid;

    const GridType grid;

    // Instantiate the GridSampler template on the grid type and on a box sampler
    // for thread-safe but uncached trilinear interpolation.
    openvdb::tools::GridSampler<GridType, openvdb::tools::BoxSampler> sampler(grid);

    // Compute the value of the grid at fractional coordinates in index space.
    GridType::ValueType indexValue = sampler.isSample(openvdb::Vec3R(10.5, -100.2, 50.3));

    // Compute the value of the grid at a location in world space.
    GridType::ValueType worldValue = sampler.wsSample(openvdb::Vec3R(0.25, 1.4, -1.1));

    // Request a value accessor for accelerated access.
    // (Because value accessors employ a cache, it is important to declare
    // one accessor per thread.)
    GridType::ConstAccessor accessor = grid.getConstAccessor();

    // Instantiate the GridSampler template on the accessor type and on
    // a box sampler for accelerated trilinear interpolation.
    openvdb::tools::GridSampler<GridType::ConstAccessor, openvdb::tools::BoxSampler>
        fastSampler(accessor, grid.transform());

    // Compute the value of the grid at fractional coordinates in index space.
    indexValue = fastSampler.isSample(openvdb::Vec3R(10.5, -100.2, 50.3));

    // Compute the value of the grid at a location in world space.
    worldValue = fastSampler.wsSample(openvdb::Vec3R(0.25, 1.4, -1.1));
}