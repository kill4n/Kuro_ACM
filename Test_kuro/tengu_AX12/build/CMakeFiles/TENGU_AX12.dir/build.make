# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.3

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build

# Include any dependencies generated for this target.
include CMakeFiles/TENGU_AX12.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TENGU_AX12.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TENGU_AX12.dir/flags.make

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj: CMakeFiles/TENGU_AX12.dir/flags.make
CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj: CMakeFiles/TENGU_AX12.dir/includes_CXX.rsp
CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj: ../src/ax_12_motor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj"
	C:\Qt\Tools\mingw492_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\TENGU_AX12.dir\src\ax_12_motor.cpp.obj -c C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\ax_12_motor.cpp

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.i"
	C:\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\ax_12_motor.cpp > CMakeFiles\TENGU_AX12.dir\src\ax_12_motor.cpp.i

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.s"
	C:\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\ax_12_motor.cpp -o CMakeFiles\TENGU_AX12.dir\src\ax_12_motor.cpp.s

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.requires:

.PHONY : CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.requires

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.provides: CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TENGU_AX12.dir\build.make CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.provides.build
.PHONY : CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.provides

CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.provides.build: CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj


CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj: CMakeFiles/TENGU_AX12.dir/flags.make
CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj: CMakeFiles/TENGU_AX12.dir/includes_C.rsp
CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj: ../src/dxl_hal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles\TENGU_AX12.dir\src\dxl_hal.c.obj   -c C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dxl_hal.c

CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.i"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -E C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dxl_hal.c > CMakeFiles\TENGU_AX12.dir\src\dxl_hal.c.i

CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.s"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -S C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dxl_hal.c -o CMakeFiles\TENGU_AX12.dir\src\dxl_hal.c.s

CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.requires:

.PHONY : CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.requires

CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.provides: CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.requires
	$(MAKE) -f CMakeFiles\TENGU_AX12.dir\build.make CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.provides.build
.PHONY : CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.provides

CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.provides.build: CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj


CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj: CMakeFiles/TENGU_AX12.dir/flags.make
CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj: CMakeFiles/TENGU_AX12.dir/includes_C.rsp
CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj: ../src/dynamixel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles\TENGU_AX12.dir\src\dynamixel.c.obj   -c C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dynamixel.c

CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.i"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -E C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dynamixel.c > CMakeFiles\TENGU_AX12.dir\src\dynamixel.c.i

CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.s"
	C:\Qt\Tools\mingw492_32\bin\gcc.exe  $(C_DEFINES) $(C_FLAGS) -S C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\dynamixel.c -o CMakeFiles\TENGU_AX12.dir\src\dynamixel.c.s

CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.requires:

.PHONY : CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.requires

CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.provides: CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.requires
	$(MAKE) -f CMakeFiles\TENGU_AX12.dir\build.make CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.provides.build
.PHONY : CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.provides

CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.provides.build: CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj


CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj: CMakeFiles/TENGU_AX12.dir/flags.make
CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj: CMakeFiles/TENGU_AX12.dir/includes_CXX.rsp
CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj"
	C:\Qt\Tools\mingw492_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\TENGU_AX12.dir\src\main.cpp.obj -c C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\main.cpp

CMakeFiles/TENGU_AX12.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TENGU_AX12.dir/src/main.cpp.i"
	C:\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\main.cpp > CMakeFiles\TENGU_AX12.dir\src\main.cpp.i

CMakeFiles/TENGU_AX12.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TENGU_AX12.dir/src/main.cpp.s"
	C:\Qt\Tools\mingw492_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\src\main.cpp -o CMakeFiles\TENGU_AX12.dir\src\main.cpp.s

CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.requires:

.PHONY : CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.requires

CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.provides: CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\TENGU_AX12.dir\build.make CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.provides.build
.PHONY : CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.provides

CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.provides.build: CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj


# Object files for target TENGU_AX12
TENGU_AX12_OBJECTS = \
"CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj" \
"CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj" \
"CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj" \
"CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj"

# External object files for target TENGU_AX12
TENGU_AX12_EXTERNAL_OBJECTS =

TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/build.make
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/linklibs.rsp
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/objects1.rsp
TENGU_AX12.exe: CMakeFiles/TENGU_AX12.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable TENGU_AX12.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\TENGU_AX12.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TENGU_AX12.dir/build: TENGU_AX12.exe

.PHONY : CMakeFiles/TENGU_AX12.dir/build

CMakeFiles/TENGU_AX12.dir/requires: CMakeFiles/TENGU_AX12.dir/src/ax_12_motor.cpp.obj.requires
CMakeFiles/TENGU_AX12.dir/requires: CMakeFiles/TENGU_AX12.dir/src/dxl_hal.c.obj.requires
CMakeFiles/TENGU_AX12.dir/requires: CMakeFiles/TENGU_AX12.dir/src/dynamixel.c.obj.requires
CMakeFiles/TENGU_AX12.dir/requires: CMakeFiles/TENGU_AX12.dir/src/main.cpp.obj.requires

.PHONY : CMakeFiles/TENGU_AX12.dir/requires

CMakeFiles/TENGU_AX12.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\TENGU_AX12.dir\cmake_clean.cmake
.PHONY : CMakeFiles/TENGU_AX12.dir/clean

CMakeFiles/TENGU_AX12.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12 C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12 C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build C:\Users\killan\Documents\GitHub\Kuro_ACM\Test_kuro\tengu_AX12\build\CMakeFiles\TENGU_AX12.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TENGU_AX12.dir/depend

