cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(scalc)

add_subdirectory (scalc)
add_subdirectory (scalc_lib)
add_subdirectory (test)