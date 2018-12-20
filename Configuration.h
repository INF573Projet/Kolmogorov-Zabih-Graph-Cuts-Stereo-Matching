//
// Created by leon on 12/18/18.
//

#ifndef KOLMOGOROV_STEREO_CONFIGURATION_H
#define KOLMOGOROV_STEREO_CONFIGURATION_H

#include <opencv2/imgproc/imgproc.hpp>
#include "image.h"
#include "ComputeEnergy.h"

using namespace cv;

struct OCCLUDED
{
    static const int value = SHRT_MAX;
};

class Configuration {
    Image<ushort> disparity; // Represents the unique configuration

public:
    Configuration(const Image<ushort> &disparity); // Construct the unique configuration given the disparity map
    Configuration(const Image<uchar> &img); // Initial configuration with all occluded pixels, corresponding to the size of the image
    Configuration(const Image<uchar> &img, ushort alpha); // Unique configuration where all the disparity is equal to alpha

    int operator()(Coord coord, int disp) const ; // Returns assignment value: active or inactive
    Image<ushort>& getDisparity() ; // Returning the pointer toward the disparity matrix

};



#endif //KOLMOGOROV_STEREO_CONFIGURATION_H
