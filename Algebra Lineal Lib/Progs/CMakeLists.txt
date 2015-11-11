cmake_minimum_required(VERSION 2.6)
project(AlgLin_Test)

set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR  ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

include_directories(${LIBS_DIR})
message(STATUS "datos: " ${LIBS_DIR})
aux_source_directory(${PROJECT_SOURCE_DIR} ${PROJECT_NAME}_SRCS)
file(GLOB ${PROJECT_NAME}_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_executable(${PROJECT_NAME} ${${PROJECT_NAME}_SRCS} ${${PROJECT_NAME}_HEADS})

target_link_libraries(${PROJECT_NAME} AlgLinLib)
