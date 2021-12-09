#include <openvdb/openvdb.h>
#include <openvdb/tools/GridTransformer.h>

int main()
{
    openvdb::initialize();

    openvdb::FloatGrid::Ptr 
        sourceGrid = openvdb::FloatGrid::create(),
        targetGrid = openvdb::FloatGrid::create();

    // Get the source and target grids' index space to world space transforms.
    const openvdb::math::Transform
        &sourceXform = sourceGrid->transform(),
        &targetXform = targetGrid->transform();
    // Compute a source grid to target grid transform.
    // (For this example, we assume that both grids' transforms are linear,
    // so that they can be represented as 4 x 4 matrices.)
    openvdb::Mat4R xform =
        sourceXform.baseMap()->getAffineMap()->getMat4() *
        targetXform.baseMap()->getAffineMap()->getMat4().inverse();

    // Create the transformer.
    openvdb::tools::GridTransformer transformer(xform);

    // Resample using nearest-neighbor interpolation.
    transformer.transformGrid<openvdb::tools::PointSampler, openvdb::FloatGrid>(
        *sourceGrid, *targetGrid);

    // Resample using trilinear interpolation.
    transformer.transformGrid<openvdb::tools::BoxSampler, openvdb::FloatGrid>(
        *sourceGrid, *targetGrid);

    // Resample using triquadratic interpolation.
    transformer.transformGrid<openvdb::tools::QuadraticSampler, openvdb::FloatGrid>(
        *sourceGrid, *targetGrid);

    // Prune the target tree for optimal sparsity.
    targetGrid->tree().prune();
}