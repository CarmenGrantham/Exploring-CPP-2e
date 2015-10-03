cmake_minimum_required(VERSION 3.2)
project(Exploring_CPP_2e)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")

set(SOURCE_FILES test.hpp Exploration53/randomint.h Exploration53/card.cpp Exploration53/card.h Exploration53/list5306.cpp)
add_executable(Exploring_CPP_2e ${SOURCE_FILES})