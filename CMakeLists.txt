cmake_minimum_required(VERSION 3.1)
project(kindofchess)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(kindofchess ${SOURCE_FILES} hw2.h hw2.cpp chess.cpp hw2main.cpp)