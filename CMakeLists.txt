cmake_minimum_required(VERSION 3.5)
project(Math)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Vector/Math.cpp Vector/Math.h Vector/Vector.cpp Vector/Vector.h)
add_executable(Math ${SOURCE_FILES})