cmake_minimum_required(VERSION 2.6)
project(KURO_imu)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
aux_source_directory(${PROJECT_SOURCE_DIR} IMU_SRCS)
include_directories(${NEKO_INCLUDE_DIR})

file(GLOB IMU_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${IMU_SRCS} ${IMU_HEADS})

target_link_libraries(${PROJECT_NAME} neko)
