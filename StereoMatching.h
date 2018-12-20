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
    void setInputsAndParameters(const Mat& imgL, const Mat& imgR, const Parameters& parameters);

public:
    StereoMatching(int minDisp, int maxDisp, int maxIter, bool is_L2, int denominator, int edgeThresh, int K, int lambda1, int lambda2);
    void operator() (const Mat& imgL, const Mat& imgR, Mat &disparity);

};


#endif //KOLMOGOROV_STEREO_STEREOMATCHING_H
