cmake_minimum_required(VERSION 3.10)
project(Kolmogorov_Stereo)

FIND_PACKAGE(OpenCV REQUIRED)

add_executable(Kolmogorov_Stereo main.cpp image.cpp image.h ComputeEnergy.h Configuration.cpp Configuration.h)
TARGET_LINK_LIBRARIES(Kolmogorov_Stereo ${OpenCV_LIBS})