//
// Created by leon on 12/18/18.
//

#include "Configuration.h"

Configuration::Configuration() {}

Configuration::Configuration(const Image<short> &disparity) {
    this->disparity = disparity;
}

Configuration::Configuration(const Image<uchar> &img) {
    Image<short> disparity(img.width(), img.height(), OCCLUDED::value);
    this->disparity = disparity;
}

Configuration::Configuration(const Image<uchar> &img, short alpha) {
    Image<short> disparity(img.width(), img.height(), alpha);
    this->disparity = disparity;
}

Configuration::~Configuration() {}

int Configuration::operator()(Coord p, int disp) const {
    if(disparity(p.x, p.y) == disp){
        return 1;
    } else {
        return 0;
    }
}

Image<short>& Configuration::getDisparity() {
    return disparity;
}

