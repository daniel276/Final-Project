cmake_minimum_required(VERSION 3.6)
project(Final_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    accountData.h
    Final_Project.cpp 1.cpp)

add_executable(Final_Project ${SOURCE_FILES})
add_executable(Admin Admin.cpp)
add_executable(1 1.cpp)