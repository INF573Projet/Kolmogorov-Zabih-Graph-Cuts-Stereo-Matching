//
// Created by leon on 12/19/18.
//

#ifndef KOLMOGOROV_STEREO_STEREOMATCHING_H
#define KOLMOGOROV_STEREO_STEREOMATCHING_H

#include <opencv2/imgproc/imgproc.hpp>
#include "ComputeEnergy.h"

using namespace cv;

class StereoMatching {
    Parameters D;
public:
    StereoMatching(float K, float lamda, int minDisp, int maxDisp, int max_it);
    void setInputsAndParameters(const Mat& imgL, const Mat& imgR, const Parameters& parameters);
    void operator() (const Mat& imgL, const Mat& imgR, Mat &disparity);

};


#endif //KOLMOGOROV_STEREO_STEREOMATCHING_H
