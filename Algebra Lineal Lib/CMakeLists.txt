cmake_minimum_required(VERSION 2.6)
project(AlgLin)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(LIBS_DIR ${CMAKE_SOURCE_DIR}/Libs/include)

add_subdirectory(Libs)
add_subdirectory(Progs)
