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
CMAKE_SOURCE_DIR = /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build

# Include any dependencies generated for this target.
include CMakeFiles/test_camara.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_camara.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_camara.dir/flags.make

CMakeFiles/test_camara.dir/src/main.cpp.o: CMakeFiles/test_camara.dir/flags.make
CMakeFiles/test_camara.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test_camara.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_camara.dir/src/main.cpp.o -c /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/src/main.cpp

CMakeFiles/test_camara.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_camara.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/src/main.cpp > CMakeFiles/test_camara.dir/src/main.cpp.i

CMakeFiles/test_camara.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_camara.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/src/main.cpp -o CMakeFiles/test_camara.dir/src/main.cpp.s

CMakeFiles/test_camara.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/test_camara.dir/src/main.cpp.o.requires

CMakeFiles/test_camara.dir/src/main.cpp.o.provides: CMakeFiles/test_camara.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/test_camara.dir/build.make CMakeFiles/test_camara.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/test_camara.dir/src/main.cpp.o.provides

CMakeFiles/test_camara.dir/src/main.cpp.o.provides.build: CMakeFiles/test_camara.dir/src/main.cpp.o

# Object files for target test_camara
test_camara_OBJECTS = \
"CMakeFiles/test_camara.dir/src/main.cpp.o"

# External object files for target test_camara
test_camara_EXTERNAL_OBJECTS =

test_camara: CMakeFiles/test_camara.dir/src/main.cpp.o
test_camara: CMakeFiles/test_camara.dir/build.make
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_ts.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_ocl.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_gpu.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_contrib.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_legacy.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_video.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.2.4.8
test_camara: /usr/lib/x86_64-linux-gnu/libopencv_core.so.2.4.8
test_camara: CMakeFiles/test_camara.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test_camara"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_camara.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_camara.dir/build: test_camara
.PHONY : CMakeFiles/test_camara.dir/build

CMakeFiles/test_camara.dir/requires: CMakeFiles/test_camara.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/test_camara.dir/requires

CMakeFiles/test_camara.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_camara.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_camara.dir/clean

CMakeFiles/test_camara.dir/depend:
	cd /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build /home/killan/kuro_min/Kuro_ACM/kuro_Core/WebUI/test_camara/build/CMakeFiles/test_camara.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_camara.dir/depend

