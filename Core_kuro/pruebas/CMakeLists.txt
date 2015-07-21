cmake_minimum_required(VERSION 2.6)
project(KURO_test)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${NEKO_INCLUDE_DIR})

aux_source_directory(${PROJECT_SOURCE_DIR} TEST_SRCS)
file(GLOB TEST_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${TEST_SRCS} ${TEST_HEADS})
target_link_libraries(${PROJECT_NAME} neko)
