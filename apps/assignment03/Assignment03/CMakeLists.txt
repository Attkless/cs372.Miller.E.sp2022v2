# CMakeList.txt : CMake project for Assignment03, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Assignment03")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../../include)

# Add source to this project's executable.
add_executable (Assignment03 "Assignment03.cpp")

# TODO: Add tests and install targets if needed.
