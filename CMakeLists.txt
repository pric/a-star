cmake_minimum_required(VERSION 3.2)
project(save_the_princess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(save_the_princess ${SOURCE_FILES} Map.cpp Map.h PathFinder.cpp PathFinder.h Utils.cpp Utils.h)