cmake_minimum_required(VERSION 3.2)
project(Exploring_CPP_2e)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES test.hpp Exploration54/list5405.cpp Exploration54/ioflags.h)
add_executable(Exploring_CPP_2e ${SOURCE_FILES})