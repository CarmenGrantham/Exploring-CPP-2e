cmake_minimum_required(VERSION 3.2)
project(Exploring_CPP_2e)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES test.hpp Exploration63/artifact.h Exploration63/artifact_impl.h Exploration63/depgraph.h Exploration63/variables.h Exploration63/list6306.cpp Exploration63/topological_sort.h Exploration63/artifact_hash.h
)
add_executable(Exploring_CPP_2e ${SOURCE_FILES})