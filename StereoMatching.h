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
    void setInputsAndParameters(const Image<uchar>& imgL, const Image<uchar>& imgR, const Parameters& parameters);

public:
    StereoMatching(int minDisp, int maxDisp, int maxIter, bool is_L2, int denominator, int edgeThresh, int K, int lambda1, int lambda2);
    void operator() (const Image<uchar>& imgL, const Image<uchar>& imgR, Image<ushort> &disparity);

    static Image<Vec3b> displayDisparity(Image<ushort> &disparity) ; // Returning the disparity displayed in the same way as the demo

};


#endif //KOLMOGOROV_STEREO_STEREOMATCHING_H
