cmake_minimum_required(VERSION 2.6)
project(KURO_KINEMATIC)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
include_directories(${NEKO_INCLUDE_DIR})

aux_source_directory(${PROJECT_SOURCE_DIR} KINEMATICS_SRCS)
file(GLOB KINEMATICS_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${KINEMATICS_SRCS} ${KINEMATICS_HEADS})
target_link_libraries(${PROJECT_NAME} neko)
