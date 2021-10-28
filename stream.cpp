#include <openvdb/openvdb.h>
#include <openvdb/io/Stream.h>
openvdb::initialize();
openvdb::GridPtrVecPtr grids(new GridPtrVec);
grids->push_back(...);
// Stream the grids to a string.
std::ostringstream ostr(std::ios_base::binary);
openvdb::io::Stream(ostr).write(*grids);
// Stream the grids to a file.
std::ofstream ofile("mygrids.vdb", std::ios_base::binary);
openvdb::io::Stream(ofile).write(*grids);
// Stream in grids from a string.
// Note that io::Stream::getGrids() returns a shared pointer
// to an openvdb::GridPtrVec.
std::istringstream istr(ostr.str(), std::ios_base::binary);
openvdb::io::Stream strm(istr);
grids = strm.getGrids();
// Stream in grids from a file.
std::ifstream ifile("mygrids.vdb", std::ios_base::binary);
grids = openvdb::io::Stream(ifile).getGrids();