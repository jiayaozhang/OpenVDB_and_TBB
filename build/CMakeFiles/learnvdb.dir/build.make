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
CMAKE_SOURCE_DIR = /home/navier/Codes/Learn_OpenVDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/navier/Codes/Learn_OpenVDB/build

# Include any dependencies generated for this target.
include CMakeFiles/learnvdb.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/learnvdb.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/learnvdb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learnvdb.dir/flags.make

CMakeFiles/learnvdb.dir/grid.cpp.o: CMakeFiles/learnvdb.dir/flags.make
CMakeFiles/learnvdb.dir/grid.cpp.o: ../grid.cpp
CMakeFiles/learnvdb.dir/grid.cpp.o: CMakeFiles/learnvdb.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/navier/Codes/Learn_OpenVDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/learnvdb.dir/grid.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learnvdb.dir/grid.cpp.o -MF CMakeFiles/learnvdb.dir/grid.cpp.o.d -o CMakeFiles/learnvdb.dir/grid.cpp.o -c /home/navier/Codes/Learn_OpenVDB/grid.cpp

CMakeFiles/learnvdb.dir/grid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learnvdb.dir/grid.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/navier/Codes/Learn_OpenVDB/grid.cpp > CMakeFiles/learnvdb.dir/grid.cpp.i

CMakeFiles/learnvdb.dir/grid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learnvdb.dir/grid.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/navier/Codes/Learn_OpenVDB/grid.cpp -o CMakeFiles/learnvdb.dir/grid.cpp.s

# Object files for target learnvdb
learnvdb_OBJECTS = \
"CMakeFiles/learnvdb.dir/grid.cpp.o"

# External object files for target learnvdb
learnvdb_EXTERNAL_OBJECTS =

learnvdb: CMakeFiles/learnvdb.dir/grid.cpp.o
learnvdb: CMakeFiles/learnvdb.dir/build.make
learnvdb: /usr/local/lib/libopenvdb.so
learnvdb: /usr/lib/x86_64-linux-gnu/libboost_iostreams.so.1.71.0
learnvdb: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
learnvdb: /usr/lib/x86_64-linux-gnu/libtbb.so
learnvdb: CMakeFiles/learnvdb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/navier/Codes/Learn_OpenVDB/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable learnvdb"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learnvdb.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learnvdb.dir/build: learnvdb
.PHONY : CMakeFiles/learnvdb.dir/build

CMakeFiles/learnvdb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learnvdb.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learnvdb.dir/clean

CMakeFiles/learnvdb.dir/depend:
	cd /home/navier/Codes/Learn_OpenVDB/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/navier/Codes/Learn_OpenVDB /home/navier/Codes/Learn_OpenVDB /home/navier/Codes/Learn_OpenVDB/build /home/navier/Codes/Learn_OpenVDB/build /home/navier/Codes/Learn_OpenVDB/build/CMakeFiles/learnvdb.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learnvdb.dir/depend
