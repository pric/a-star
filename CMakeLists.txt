cmake_minimum_required(VERSION 3.2)
project(save_the_princess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

set(SOURCE_FILES src/main.cpp)
add_executable(save_the_princess ${SOURCE_FILES} src/Map.cpp src/Map.h src/PathFinder.cpp src/PathFinder.h src/Utils.cpp src/Utils.h)