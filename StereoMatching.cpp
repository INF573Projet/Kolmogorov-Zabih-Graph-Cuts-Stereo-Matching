//
// Created by leon on 12/19/18.
//

#include "StereoMatching.h"

StereoMatching::StereoMatching(float K, float lamda, int minDisp, int maxDisp, int max_it) {
    /* Constructor: setting the parameters */
}


void StereoMatching::setInputsAndParameters(const Mat &imgL, const Mat &imgR, const Parameters &parameters) {
    /* Set the global variables in GraphCut */

}

void StereoMatching::operator()(const Mat &imgL, const Mat &imgR, Mat &disparity) {
    setInputsAndParameters(imgL, imgR, this->D);
    for(int i=0; i< this->D.max_it; i++){
        int alpha = 0; //TODO random value of alpha
        
    }

}