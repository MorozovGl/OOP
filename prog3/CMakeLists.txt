cmake_minimum_required(VERSION 3.8)
project(prog3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/main.cpp src/wav.cpp src/wav_core.cpp src/wav.h src/wav_core.h src/wav_header.h src/WavExceptions.h)
add_executable(prog3 ${SOURCE_FILES})