cmake_minimum_required(VERSION 3.2)
project(a_star)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(SOURCE_FILES src/main.cpp)
add_executable(a_star ${SOURCE_FILES} src/Grid.cpp src/Grid.h src/PathFinder.cpp src/PathFinder.h src/Utils.cpp src/Utils.h)