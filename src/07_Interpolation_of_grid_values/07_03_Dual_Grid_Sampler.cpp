#include <openvdb/openvdb.h>
#include <openvdb/tools/Interpolation.h>

int main()
{
    openvdb::initialize();

    using GridType = openvdb::FloatGrid;

    const GridType sourceGrid, targetGrid;

    // Instantiate the DualGridSampler template on the grid type and on
    // a box sampler for thread-safe but uncached trilinear interpolation.
    openvdb::tools::DualGridSampler<GridType, openvdb::tools::BoxSampler>
        sampler(sourceGrid, targetGrid.constTransform());

    // Compute the value of the source grid at a location in the
    // target grid's index space.
    GridType::ValueType value = sampler(openvdb::Coord(-23, -50, 202));

    // Request a value accessor for accelerated access to the source grid.
    // (Because value accessors employ a cache, it is important to declare
    // one accessor per thread.)
    GridType::ConstAccessor accessor = sourceGrid.getConstAccessor();

    // Instantiate the DualGridSampler template on the accessor type and on
    // a box sampler for accelerated trilinear interpolation.
    openvdb::tools::DualGridSampler<GridType::ConstAccessor, openvdb::tools::BoxSampler>
        fastSampler(accessor, sourceGrid.constTransform(), targetGrid.constTransform());

    // Compute the value of the source grid at a location in the
    // target grid's index space.
    value = fastSampler(openvdb::Coord(-23, -50, 202));
}