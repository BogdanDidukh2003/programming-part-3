cmake_minimum_required(VERSION 3.14)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab1 main.cpp models/Helicopter.cpp models/Helicopter.h models/HelicoptersManager.cpp models/HelicoptersManager.h)