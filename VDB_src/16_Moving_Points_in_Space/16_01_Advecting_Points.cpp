#include <openvdb/openvdb.h>
#include <openvdb/points/PointAdvect.h>
#include <openvdb/points/PointConversion.h>

int main()
{
    openvdb::initialize();

    openvdb::points::PointDataGrid::Ptr points = openvdb::points::PointDataGrid::create();

    // Create an empty velocity grid with gravity as background value
    auto gravity = openvdb::Vec3SGrid::create(openvdb::Vec3s(0, -9.81, 0));

    // Advect points in-place using gravity velocity grid
    openvdb::points::advectPoints(*points, *gravity,
                                  /*integrationOrder=*/4, /*dt=*/1.0 / 24.0, /*timeSteps=*/1);
}