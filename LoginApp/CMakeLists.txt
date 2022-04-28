cmake_minimum_required(VERSION 3.21)
project(LoginApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(LoginApp main.cpp LoginFunctions.cpp LoginFunctions.h)
add_executable(LoginFunctions_cpp LoginFunctions.cpp)
