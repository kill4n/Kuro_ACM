# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.3.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.3.0/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build"

# Include any dependencies generated for this target.
include Libs/CMakeFiles/AlgLinLib.dir/depend.make

# Include the progress variables for this target.
include Libs/CMakeFiles/AlgLinLib.dir/progress.make

# Include the compile flags for this target's objects.
include Libs/CMakeFiles/AlgLinLib.dir/flags.make

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o: Libs/CMakeFiles/AlgLinLib.dir/flags.make
Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o: ../Libs/src/matrizal.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o"
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o -c "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/Libs/src/matrizal.cpp"

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.i"
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/Libs/src/matrizal.cpp" > CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.i

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.s"
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/Libs/src/matrizal.cpp" -o CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.s

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.requires:

.PHONY : Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.requires

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.provides: Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.requires
	$(MAKE) -f Libs/CMakeFiles/AlgLinLib.dir/build.make Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.provides.build
.PHONY : Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.provides

Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.provides.build: Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o


# Object files for target AlgLinLib
AlgLinLib_OBJECTS = \
"CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o"

# External object files for target AlgLinLib
AlgLinLib_EXTERNAL_OBJECTS =

../build_Darwin/libAlgLinLib.dylib: Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o
../build_Darwin/libAlgLinLib.dylib: Libs/CMakeFiles/AlgLinLib.dir/build.make
../build_Darwin/libAlgLinLib.dylib: Libs/CMakeFiles/AlgLinLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library ../../build_Darwin/libAlgLinLib.dylib"
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AlgLinLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Libs/CMakeFiles/AlgLinLib.dir/build: ../build_Darwin/libAlgLinLib.dylib

.PHONY : Libs/CMakeFiles/AlgLinLib.dir/build

Libs/CMakeFiles/AlgLinLib.dir/requires: Libs/CMakeFiles/AlgLinLib.dir/src/matrizal.cpp.o.requires

.PHONY : Libs/CMakeFiles/AlgLinLib.dir/requires

Libs/CMakeFiles/AlgLinLib.dir/clean:
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" && $(CMAKE_COMMAND) -P CMakeFiles/AlgLinLib.dir/cmake_clean.cmake
.PHONY : Libs/CMakeFiles/AlgLinLib.dir/clean

Libs/CMakeFiles/AlgLinLib.dir/depend:
	cd "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib" "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/Libs" "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build" "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs" "/Users/crhistian/Documents/GitHub/Kuro_ACM/Algebra Lineal Lib/build/Libs/CMakeFiles/AlgLinLib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : Libs/CMakeFiles/AlgLinLib.dir/depend

