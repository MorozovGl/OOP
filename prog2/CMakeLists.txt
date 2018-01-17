cmake_minimum_required(VERSION 3.8)
project(prog2)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/StatisticMultiset.h)
add_executable(prog2 ${SOURCE_FILES})