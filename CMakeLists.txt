cmake_minimum_required(VERSION 3.5)
project(translete)

if(CMAKE_COMPILER_IS_GNUCXX)
    add_definitions(-Wall -g -O0)
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build/bin)

add_subdirectory(src)