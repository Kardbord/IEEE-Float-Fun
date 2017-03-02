cmake_minimum_required(VERSION 3.6)
project(intToFloat)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp IEEEFloat.cpp IEEEFloat.h)
add_executable(intToFloat ${SOURCE_FILES})