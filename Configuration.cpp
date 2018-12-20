//
// Created by leon on 12/18/18.
//

#include "Configuration.h"

Configuration::Configuration(const Image<ushort> &disparity) {
    this->disparity = disparity;
}

Configuration::Configuration(const Image<uchar> &img) {
    Image<ushort> disparity(img.width(), img.height(), OCCLUDED::value);
    this->disparity = disparity;
}

Configuration::Configuration(const Image<uchar> &img, ushort alpha) {
    Image<ushort> disparity(img.width(), img.height(), alpha);
    this->disparity = disparity;
}

int Configuration::operator()(Coord p, int disp) const {
    if(disparity(p.x, p.y) == disp){
        return 1;
    } else {
        return 0;
    }
}