# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/killan/kuro_min/Kuro_ACM/kuro_Core

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/killan/kuro_min/Kuro_ACM/kuro_Core/build

# Include any dependencies generated for this target.
include test/test_motor_pro/CMakeFiles/test_motor_pro.dir/depend.make

# Include the progress variables for this target.
include test/test_motor_pro/CMakeFiles/test_motor_pro.dir/progress.make

# Include the compile flags for this target's objects.
include test/test_motor_pro/CMakeFiles/test_motor_pro.dir/flags.make

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/flags.make
test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o: ../test/test_motor_pro/src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_motor_pro.dir/src/main.cpp.o -c /home/killan/kuro_min/Kuro_ACM/kuro_Core/test/test_motor_pro/src/main.cpp

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_motor_pro.dir/src/main.cpp.i"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/killan/kuro_min/Kuro_ACM/kuro_Core/test/test_motor_pro/src/main.cpp > CMakeFiles/test_motor_pro.dir/src/main.cpp.i

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_motor_pro.dir/src/main.cpp.s"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/killan/kuro_min/Kuro_ACM/kuro_Core/test/test_motor_pro/src/main.cpp -o CMakeFiles/test_motor_pro.dir/src/main.cpp.s

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.requires:
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.requires

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.provides: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.requires
	$(MAKE) -f test/test_motor_pro/CMakeFiles/test_motor_pro.dir/build.make test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.provides.build
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.provides

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.provides.build: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o

# Object files for target test_motor_pro
test_motor_pro_OBJECTS = \
"CMakeFiles/test_motor_pro.dir/src/main.cpp.o"

# External object files for target test_motor_pro
test_motor_pro_EXTERNAL_OBJECTS =

../build_Linux/test_motor_pro: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o
../build_Linux/test_motor_pro: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/build.make
../build_Linux/test_motor_pro: ../build_Linux/libdynamixel_pro_aux.so
../build_Linux/test_motor_pro: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../build_Linux/test_motor_pro"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_motor_pro.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/test_motor_pro/CMakeFiles/test_motor_pro.dir/build: ../build_Linux/test_motor_pro
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/build

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/requires: test/test_motor_pro/CMakeFiles/test_motor_pro.dir/src/main.cpp.o.requires
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/requires

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/clean:
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro && $(CMAKE_COMMAND) -P CMakeFiles/test_motor_pro.dir/cmake_clean.cmake
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/clean

test/test_motor_pro/CMakeFiles/test_motor_pro.dir/depend:
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/kuro_min/Kuro_ACM/kuro_Core /home/killan/kuro_min/Kuro_ACM/kuro_Core/test/test_motor_pro /home/killan/kuro_min/Kuro_ACM/kuro_Core/build /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/test/test_motor_pro/CMakeFiles/test_motor_pro.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/test_motor_pro/CMakeFiles/test_motor_pro.dir/depend
