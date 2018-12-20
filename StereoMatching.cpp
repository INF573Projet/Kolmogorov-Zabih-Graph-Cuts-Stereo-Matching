//
// Created by leon on 12/19/18.
//

#include "StereoMatching.h"
#include "Configuration.h"
#include <iostream>

using namespace std;


StereoMatching::StereoMatching(int minDisp, int maxDisp, int maxIter, bool is_L2, int denominator, int edgeThresh, int K, int lambda1, int lambda2) {
    Parameters param;
    param.is_L2 = is_L2;
    param.denominator = denominator;
    param.edgeThresh = edgeThresh;
    param.lambda1 = lambda1;
    param.lambda2 = lambda2;
    param.K = K;
    param.minDisp = minDisp;
    param.maxDisp = maxDisp;
    param.maxIter = maxIter;

    this->D = param;
}

void StereoMatching::setInputsAndParameters(const Image<uchar> &imgL, const Image<uchar> &imgR, const Parameters &parameters) {
    /* Set the global variables in GraphCut */
    cout << "Setting parameters..." << endl;
}

Image<Vec3b> StereoMatching::displayDisparity(Image<ushort> &disparity) {
    Image<Vec3b> dispImg(disparity.width(), disparity.height(), Vec3b(255, 255, 0));
    //TODO complete same as Python
    return dispImg;

}


void StereoMatching::operator()(const Image<uchar> &imgL, const Image<uchar> &imgR, Image<ushort> &disparity) {
    cout << "Computing disparity..." << endl;
    setInputsAndParameters(imgL, imgR, this->D);

    Configuration f(imgL); // Set initial configuration where all assignments are inactive

    for(int i=0; i< D.maxIter; i++){
        int alpha = 0; //TODO random value of alpha

        
    }
    disparity = f.getDisparity();
}