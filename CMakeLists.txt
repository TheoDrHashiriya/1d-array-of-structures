cmake_minimum_required(VERSION 3.10.0)
project(1D-array-of-structures VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(1D-array-of-structures
src/main.cpp
src/menu.cpp
src/student.cpp
src/utils.cpp)

target_include_directories(1D-array-of-structures PRIVATE include/)