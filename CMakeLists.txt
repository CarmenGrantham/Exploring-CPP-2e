cmake_minimum_required(VERSION 3.2)
project(Exploring_CPP_2e)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES test.hpp Exploration49/list4907.cpp Exploration49/rational.h)
add_executable(Exploring_CPP_2e ${SOURCE_FILES})