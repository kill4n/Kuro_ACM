cmake_minimum_required(VERSION 2.6)
project(neko)

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin") # Mirar el SO
    cmake_policy(SET CMP0042 NEW)
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(PROJECT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories(${PROJECT_INCLUDE_DIR})
include_directories(${PROJECT_SOURCE_DIR})
aux_source_directory(${PROJECT_SOURCE_DIR} NEKO_SRCS)

file(GLOB NEKO_HEADS "${PROJECT_INCLUDE_DIR}/*.h")

add_library(${PROJECT_NAME} SHARED ${NEKO_SRCS} ${NEKO_HEADS})
