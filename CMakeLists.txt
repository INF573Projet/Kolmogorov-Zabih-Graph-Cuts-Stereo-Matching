cmake_minimum_required(VERSION 3.10)
project(Kolmogorov_Stereo)

FIND_PACKAGE(OpenCV REQUIRED)

add_executable(Kolmogorov_Stereo main.cpp image.cpp image.h ComputeEnergy.h Configuration.cpp Configuration.h StereoMatching.cpp StereoMatching.h GraphCut.cpp GraphCut.h)
TARGET_LINK_LIBRARIES(Kolmogorov_Stereo ${OpenCV_LIBS})

add_executable(test_configuration Configuration.cpp Configuration.h TestConfiguration.cpp)
TARGET_LINK_LIBRARIES(test_configuration ${OpenCV_LIBS})

add_executable(test-stereo_matching StereoMatching.cpp StereoMatching.h ComputeEnergy.h TestStereoMatching.cpp)
TARGET_LINK_LIBRARIES(test-stereo_matching ${OpenCV_LIBS})