cmake_minimum_required(VERSION 3.8)
project(prog1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/main.cpp
        src/IniParser/IniParser.cpp
        src/IniParser/IniParser.h
        src/IniParserException/IniParserException.cpp
        src/IniParserException/IniParserException.h)


add_executable(prog1 ${SOURCE_FILES})