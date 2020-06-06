cmake_minimum_required(VERSION 3.16)
project(Tetris)

set(CMAKE_CXX_STANDARD 14)

add_executable(Tetris main.cpp Mechanism.cpp Mechanism.h Base.h Windows.h Windows.cpp Schedule.h Schedule.cpp Control.h Control.cpp Base.cpp)