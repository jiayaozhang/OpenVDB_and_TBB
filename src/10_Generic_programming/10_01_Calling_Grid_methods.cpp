#include <openvdb/openvdb.h>

template <typename OpType>
void processTypedGrid(openvdb::GridBase::Ptr grid, OpType &op)
{
#define CALL_OP(GridType) \
    op.template operator()<GridType>(openvdb::gridPtrCast<GridType>(grid))

    if (grid->isType<openvdb::BoolGrid>())
        CALL_OP(openvdb::BoolGrid);
    else if (grid->isType<openvdb::FloatGrid>())
        CALL_OP(openvdb::FloatGrid);
    else if (grid->isType<openvdb::DoubleGrid>())
        CALL_OP(openvdb::DoubleGrid);
    else if (grid->isType<openvdb::Int32Grid>())
        CALL_OP(openvdb::Int32Grid);
    else if (grid->isType<openvdb::Int64Grid>())
        CALL_OP(openvdb::Int64Grid);
    else if (grid->isType<openvdb::Vec3IGrid>())
        CALL_OP(openvdb::Vec3IGrid);
    else if (grid->isType<openvdb::Vec3SGrid>())
        CALL_OP(openvdb::Vec3SGrid);
    else if (grid->isType<openvdb::Vec3DGrid>())
        CALL_OP(openvdb::Vec3DGrid);
    else if (grid->isType<openvdb::StringGrid>())
        CALL_OP(openvdb::StringGrid);

#undef CALL_OP
}

// Define a functor that prunes the trees of grids of arbitrary type
// with a fixed pruning tolerance.
struct PruneOp
{
    double tolerance;
    PruneOp(double t) : tolerance(t) {}

    template <typename GridType>
    void operator()(typename GridType::Ptr grid) const
    {
        grid->tree().prune(typename GridType::ValueType(tolerance));
    }
    // Overload to handle string-valued grids
    void operator()(openvdb::StringGrid::Ptr grid) const
    {
        grid->tree().prune();
    }
};

int main()
{
    openvdb::initialize();

    // Read all grids from a file.
    openvdb::io::File file("mygrids.vdb");
    file.open();
    openvdb::GridPtrVecPtr myGrids = file.getGrids();
    file.close();

    // Prune each grid with a tolerance of 1%.
    const PruneOp pruner(/*tolerance=*/0.01);
    for (openvdb::GridPtrVecIter iter = myGrids->begin();
         iter != myGrids->end(); ++iter)
    {
        openvdb::GridBase::Ptr grid = *iter;
        processTypedGrid(grid, pruner);
    }
}