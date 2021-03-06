cmake_minimum_required(VERSION 2.6)
project(KURO_master)
find_package(OpenCV REQUIRED)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

include_directories(${NEKO_INCLUDE_DIR})
aux_source_directory(${PROJECT_SOURCE_DIR} MASTER_SRCS)
file(GLOB MASTER_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

include_directories(${LIBS_DIR})
include_directories(${PERIF_DIR})
include_directories(${KINE_DIR})

add_executable(${PROJECT_NAME} ${MASTER_SRCS} ${MASTER_HEADS})

target_link_libraries(${PROJECT_NAME} joystick omni_model difer_model acker_model camara socket_aux ${OpenCV_LIBS})
