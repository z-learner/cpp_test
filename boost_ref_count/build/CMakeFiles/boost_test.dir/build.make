# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/friden/test/boost_ref_count

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/friden/test/boost_ref_count/build

# Include any dependencies generated for this target.
include CMakeFiles/boost_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boost_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boost_test.dir/flags.make

CMakeFiles/boost_test.dir/main.cc.o: CMakeFiles/boost_test.dir/flags.make
CMakeFiles/boost_test.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/friden/test/boost_ref_count/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boost_test.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boost_test.dir/main.cc.o -c /home/friden/test/boost_ref_count/main.cc

CMakeFiles/boost_test.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_test.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/friden/test/boost_ref_count/main.cc > CMakeFiles/boost_test.dir/main.cc.i

CMakeFiles/boost_test.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_test.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/friden/test/boost_ref_count/main.cc -o CMakeFiles/boost_test.dir/main.cc.s

# Object files for target boost_test
boost_test_OBJECTS = \
"CMakeFiles/boost_test.dir/main.cc.o"

# External object files for target boost_test
boost_test_EXTERNAL_OBJECTS =

boost_test: CMakeFiles/boost_test.dir/main.cc.o
boost_test: CMakeFiles/boost_test.dir/build.make
boost_test: /usr/lib/x86_64-linux-gnu/libboost_timer.so.1.71.0
boost_test: /usr/lib/x86_64-linux-gnu/libboost_chrono.so.1.71.0
boost_test: CMakeFiles/boost_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/friden/test/boost_ref_count/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boost_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/boost_test.dir/build: boost_test

.PHONY : CMakeFiles/boost_test.dir/build

CMakeFiles/boost_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boost_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boost_test.dir/clean

CMakeFiles/boost_test.dir/depend:
	cd /home/friden/test/boost_ref_count/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/friden/test/boost_ref_count /home/friden/test/boost_ref_count /home/friden/test/boost_ref_count/build /home/friden/test/boost_ref_count/build /home/friden/test/boost_ref_count/build/CMakeFiles/boost_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boost_test.dir/depend

