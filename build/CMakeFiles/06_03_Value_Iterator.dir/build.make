# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/navier/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/navier/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/navier/Documents/OpenVDB_Cookbook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/navier/Documents/OpenVDB_Cookbook/build

# Include any dependencies generated for this target.
include CMakeFiles/06_03_Value_Iterator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/06_03_Value_Iterator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/06_03_Value_Iterator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/06_03_Value_Iterator.dir/flags.make

CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o: CMakeFiles/06_03_Value_Iterator.dir/flags.make
CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o: ../src/06_Iteration/06_03_Value_Iterator.cpp
CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o: CMakeFiles/06_03_Value_Iterator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/navier/Documents/OpenVDB_Cookbook/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o -MF CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o.d -o CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o -c /home/navier/Documents/OpenVDB_Cookbook/src/06_Iteration/06_03_Value_Iterator.cpp

CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.i"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/navier/Documents/OpenVDB_Cookbook/src/06_Iteration/06_03_Value_Iterator.cpp > CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.i

CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.s"
	/bin/x86_64-linux-gnu-g++-10 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/navier/Documents/OpenVDB_Cookbook/src/06_Iteration/06_03_Value_Iterator.cpp -o CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.s

# Object files for target 06_03_Value_Iterator
06_03_Value_Iterator_OBJECTS = \
"CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o"

# External object files for target 06_03_Value_Iterator
06_03_Value_Iterator_EXTERNAL_OBJECTS =

06_03_Value_Iterator: CMakeFiles/06_03_Value_Iterator.dir/src/06_Iteration/06_03_Value_Iterator.cpp.o
06_03_Value_Iterator: CMakeFiles/06_03_Value_Iterator.dir/build.make
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libopenvdb.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libblosc.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/lib/libtbb.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libboost_iostreams.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libboost_regex.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libboost_system.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/liblz4d.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libsnappyd.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libz.a
06_03_Value_Iterator: /home/navier/Develop/vcpkg/installed/x64-linux/debug/lib/libzstdd.a
06_03_Value_Iterator: CMakeFiles/06_03_Value_Iterator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/navier/Documents/OpenVDB_Cookbook/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 06_03_Value_Iterator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/06_03_Value_Iterator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/06_03_Value_Iterator.dir/build: 06_03_Value_Iterator
.PHONY : CMakeFiles/06_03_Value_Iterator.dir/build

CMakeFiles/06_03_Value_Iterator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/06_03_Value_Iterator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/06_03_Value_Iterator.dir/clean

CMakeFiles/06_03_Value_Iterator.dir/depend:
	cd /home/navier/Documents/OpenVDB_Cookbook/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/navier/Documents/OpenVDB_Cookbook /home/navier/Documents/OpenVDB_Cookbook /home/navier/Documents/OpenVDB_Cookbook/build /home/navier/Documents/OpenVDB_Cookbook/build /home/navier/Documents/OpenVDB_Cookbook/build/CMakeFiles/06_03_Value_Iterator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/06_03_Value_Iterator.dir/depend
