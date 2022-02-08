# CMakeList.txt : CMake project for assignment04, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("assignment04")

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(../../include)

# Add source to this project's executable.
add_executable (assignment04 "assignment04.cpp" "assignment04.h" "stack.h")

# TODO: Add tests and install targets if needed.
