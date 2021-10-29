cmake_minimum_required(VERSION 3.18)

project(jiayao LANGUAGES CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} /usr/local/lib/cmake/OpenVDB/)

find_package(OpenVDB REQUIRED)
add_executable(learnvdb  random.cpp)

target_link_libraries(learnvdb OpenVDB::openvdb)
