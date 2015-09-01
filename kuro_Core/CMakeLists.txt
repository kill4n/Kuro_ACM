cmake_minimum_required(VERSION 2.6)
project(kuroproject)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build_${CMAKE_SYSTEM_NAME})
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(PROJECT_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

set(LIBS_DIR ${CMAKE_SOURCE_DIR}/librerias)
set(MOTOR_DIR ${CMAKE_SOURCE_DIR}/motores)
set(PRIF_DIR ${CMAKE_SOURCE_DIR}/perifericos)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")
#add_subdirectory(master)

#add_subdirectory(status)
#add_subdirectory(comunicacion)

#add_subdirectory(sensores)
add_subdirectory(motores)
add_subdirectory(perifericos)

#add_subdirectory(cinematica)

add_subdirectory(librerias)

add_subdirectory(test)
