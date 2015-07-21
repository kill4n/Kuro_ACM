cmake_minimum_required(VERSION 2.6)
project (supervisor)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)

set (PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set (PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

#add_subdirectory(project1)
#add_subdirectory(project2)

#set(PROJECT1_SRCS 
#${PROJECT_SOURCE_DIR}/some.cpp
#${PROJECT_SOURCE_DIR}/someother.cpp
#)

#include_directories("${PROJECT_BINARY_DIR}")
#include_directories("${PROJECT_INCLUDE_DIR}")

#add_library(${PROJECT_NAME} SHARED ${PROJECT1_SRCS})
