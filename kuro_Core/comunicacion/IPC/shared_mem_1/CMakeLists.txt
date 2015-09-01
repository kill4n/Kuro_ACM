cmake_minimum_required(VERSION 2.6)
project(SH_MEM_1)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

aux_source_directory(${PROJECT_SOURCE_DIR} SH_MEM_1_SRCS)
file(GLOB SH_MEM_1_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${SH_MEM_1_SRCS} ${SH_MEM_1_HEADS})
