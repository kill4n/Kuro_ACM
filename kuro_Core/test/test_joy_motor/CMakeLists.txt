cmake_minimum_required(VERSION 2.6)
project(test_joy_motor)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

aux_source_directory(${PROJECT_SOURCE_DIR} ${PROJECT_NAME}_SRCS)
file(GLOB ${PROJECT_NAME}_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

include_directories(${LIBS_DIR})
include_directories(${PERIF_DIR})
include_directories(${MOTOR_DIR})

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_HEADS})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} joystick ax_12 dynamixel_aux)
