cmake_minimum_required(VERSION 3.8)
project(prog4)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/PrimeFactoring.cpp src/PrimeFactoring.h)
add_executable(prog4 ${SOURCE_FILES})