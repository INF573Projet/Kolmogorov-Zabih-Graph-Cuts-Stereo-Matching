//
// Created by leon on 12/19/18.
//

#include "StereoMatching.h"
#include "Configuration.h"
#include "GraphCut.h"
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

StereoMatching::~StereoMatching() {}

void StereoMatching::setInputsAndParameters(const Image<uchar> &imgL, const Image<uchar> &imgR, const Parameters &parameters) {
    /* Set the global variables in GraphCut */
    cout << "Setting parameters..." << endl;
}

Image<Vec3b> StereoMatching::dispImage(Image<short> &disparity) {
    Image<Vec3b> dispImg(disparity.width(), disparity.height(), Vec3b(255, 255, 0));
    //TODO complete same as Python - flatten to eliminate OCCLUDED
    return dispImg;

}


void StereoMatching::operator()(const Image<uchar> &imgL, const Image<uchar> &imgR, Image<short> &disparity) {
    cout << "Computing disparity..." << endl;
    setInputsAndParameters(imgL, imgR, D);

    Configuration f(imgL); // Set initial configuration where all assignments are inactive

    int dispRange = D.maxDisp - D.minDisp + 1;

    for(int i=0; i< D.maxIter; i++){
        for(int j=0; j< dispRange; j++){
            int alpha = 0; //TODO random value of alpha
            GraphCut g(imgL, imgR, alpha, f, D);
            Configuration new_f;
            g.expansionMove(new_f);
            f = new_f;
        }
    }
    disparity = f.getDisparity();
}