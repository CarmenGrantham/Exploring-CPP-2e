cmake_minimum_required(VERSION 3.2)
project(Exploring_CPP_2e)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES test.hpp Exploration59/list5910.cpp Exploration59/artifact.h Exploration59/topological_sort.h
    Exploration59/variables.h Exploration59/variables.cpp)
add_executable(Exploring_CPP_2e ${SOURCE_FILES})