#include <openvdb/openvdb.h>
#include <openvdb/points/PointMove.h>
#include <openvdb/points/PointConversion.h>

// This custom deformer is also used in the TestPointMove unit tests.
struct OffsetDeformer
{
    OffsetDeformer(const openvdb::Vec3d &_offset)
        : offset(_offset) {}

    template <typename LeafIterT>
    void reset(const LeafIterT &, size_t) {}

    template <typename IndexIterT>
    void apply(openvdb::Vec3d &position, const IndexIterT &) const
    {
        position += offset;
    }

    openvdb::Vec3d offset;
};

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataGrid::Ptr points = openvdb::points::PointDataGrid::create();

    // Create an OffsetDeformer that moves the points downwards in Y by 10 world-space units.
    openvdb::Vec3d offset(0, -10, 0);
    OffsetDeformer deformer(offset);

    // Move the points using this deformer
    openvdb::points::movePoints(*points, deformer);
}