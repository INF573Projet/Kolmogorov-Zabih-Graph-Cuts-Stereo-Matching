cmake_minimum_required(VERSION 3.13)
project(Kolmogorov_Stereo)

FIND_PACKAGE(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 14)

add_executable(Kolmogorov_Stereo src/main.cpp src/image.cpp src/image.h)