# CMakeList.txt : CMake project for Assignment05, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Assignment05")

set(CMAKE_CXX_STANDARD 11) 
set(CMAKE_CXX_STANDARD_REQUIRED true)

include_directories(../../include)

# Add source to this project's executable.
add_executable (Assignment05 "Assignment05.cpp")

# TODO: Add tests and install targets if needed.
