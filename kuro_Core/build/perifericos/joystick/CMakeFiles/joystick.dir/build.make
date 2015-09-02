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
include perifericos/joystick/CMakeFiles/joystick.dir/depend.make

# Include the progress variables for this target.
include perifericos/joystick/CMakeFiles/joystick.dir/progress.make

# Include the compile flags for this target's objects.
include perifericos/joystick/CMakeFiles/joystick.dir/flags.make

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o: perifericos/joystick/CMakeFiles/joystick.dir/flags.make
perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o: ../perifericos/joystick/src/joystick_helper.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/joystick.dir/src/joystick_helper.cpp.o -c /home/killan/kuro_min/Kuro_ACM/kuro_Core/perifericos/joystick/src/joystick_helper.cpp

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/joystick.dir/src/joystick_helper.cpp.i"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/killan/kuro_min/Kuro_ACM/kuro_Core/perifericos/joystick/src/joystick_helper.cpp > CMakeFiles/joystick.dir/src/joystick_helper.cpp.i

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/joystick.dir/src/joystick_helper.cpp.s"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/killan/kuro_min/Kuro_ACM/kuro_Core/perifericos/joystick/src/joystick_helper.cpp -o CMakeFiles/joystick.dir/src/joystick_helper.cpp.s

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.requires:
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.requires

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.provides: perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.requires
	$(MAKE) -f perifericos/joystick/CMakeFiles/joystick.dir/build.make perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.provides.build
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.provides

perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.provides.build: perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o

# Object files for target joystick
joystick_OBJECTS = \
"CMakeFiles/joystick.dir/src/joystick_helper.cpp.o"

# External object files for target joystick
joystick_EXTERNAL_OBJECTS =

../build_Linux/libjoystick.so: perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o
../build_Linux/libjoystick.so: perifericos/joystick/CMakeFiles/joystick.dir/build.make
../build_Linux/libjoystick.so: ../build_Linux/libthread_aux.so
../build_Linux/libjoystick.so: perifericos/joystick/CMakeFiles/joystick.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library ../../../build_Linux/libjoystick.so"
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/joystick.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
perifericos/joystick/CMakeFiles/joystick.dir/build: ../build_Linux/libjoystick.so
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/build

perifericos/joystick/CMakeFiles/joystick.dir/requires: perifericos/joystick/CMakeFiles/joystick.dir/src/joystick_helper.cpp.o.requires
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/requires

perifericos/joystick/CMakeFiles/joystick.dir/clean:
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick && $(CMAKE_COMMAND) -P CMakeFiles/joystick.dir/cmake_clean.cmake
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/clean

perifericos/joystick/CMakeFiles/joystick.dir/depend:
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/kuro_min/Kuro_ACM/kuro_Core /home/killan/kuro_min/Kuro_ACM/kuro_Core/perifericos/joystick /home/killan/kuro_min/Kuro_ACM/kuro_Core/build /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick /home/killan/kuro_min/Kuro_ACM/kuro_Core/build/perifericos/joystick/CMakeFiles/joystick.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : perifericos/joystick/CMakeFiles/joystick.dir/depend

