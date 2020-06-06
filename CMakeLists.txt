cmake_minimum_required(VERSION 3.16)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris main.cpp Windows.cpp Mechanism.cpp Schedule.cpp Control.cpp)