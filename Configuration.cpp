//
// Created by leon on 12/18/18.
//

#include "Configuration.h"

Configuration::Configuration(const Mat &conf) {
    /* conf is a Cubic matrix */
    if(validConfMatrix()){
        this->conf = conf;
    } else {
        throw std::invalid_argument("Configuration matrix isn't valid: need a 3D matrix with correct size");
    }
}

Configuration::Configuration(const Mat &image, int minDisp, int maxDisp) {
    /* Constructor with all inactive assignments, given an image and the disparity range */
    int sizes[] = {image.rows, image.cols, maxDisp - minDisp + 1 };
    Mat conf = Mat(3, sizes, CV_8U, Scalar(0));
    this->conf = conf;
}

bool Configuration::validConfMatrix(){
    /* Verify if the configuration matrix is a valid format */
    return true;
}

Mat Configuration::computeDisparity(){
    /* Compute the disparity given the assignments */
    return Mat();
}

