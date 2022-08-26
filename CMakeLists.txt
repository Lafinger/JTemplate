cmake_minimum_required(VERSION 3.14 FATAL_ERROR)

project(JTemplate)
message(STATUS "[Project] ${PROJECT_NAME}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(JTemplate main.cpp)