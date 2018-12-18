//
// Created by leon on 12/18/18.
//

#ifndef KOLMOGOROV_STEREO_CONFIGURATION_H
#define KOLMOGOROV_STEREO_CONFIGURATION_H

#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

class Configuration {
    Mat conf; // Cube matrix, shape = (w, h, maxDisp-minDisp+1)
    Mat disparity;

public:
    Configuration(const Mat& conf); //constructor with explicit assignments
    Configuration(const Mat& image, int minDisp, int maxDisp); //constructor with all inactive assignments, given an image and the disparity range
    Mat computeDisparity();
    bool validConfMatrix();

    inline int operator()(int x, int y, int d) const { return conf.at<uchar>(y, x, d); } //Access the values of the assignment

};



#endif //KOLMOGOROV_STEREO_CONFIGURATION_H
