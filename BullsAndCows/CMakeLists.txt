cmake_minimum_required(VERSION 3.29)
project(bulls_and_cows_v3)

set(CMAKE_CXX_STANDARD 20)

add_executable(bulls_and_cows_v3 main.cpp
        functions.cpp
        functions.h)
