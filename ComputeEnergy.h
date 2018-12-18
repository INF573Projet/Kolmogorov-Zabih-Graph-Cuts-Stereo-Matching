//
// Created by jiabin on 2018/12/18.
//

#ifndef KOLMOGOROV_STEREO_COMPUTEENERGY_H
#define KOLMOGOROV_STEREO_COMPUTEENERGY_H

#include "image.h"

struct Coord{
    Coord(int x, int y) : x(x), y(y) {}

    int x;
    int y; };

struct Parameters
{
    bool is_L2; ///< Data term
    /// Data term must be multiplied by denominator.
    /// Equivalent to using lambda1/denom, lambda2/denom, K/denom
    int denominator;

    // Smoothness term
    int edgeThresh; ///< Intensity level diff for 'edge'
    int lambda1; ///< Smoothness cost not across edge
    int lambda2; ///< Smoothness cost across edge (should be <=lambda1)
    int K; ///< Penalty for inactive assignment

    int maxIter; ///< Maximum number of iterations


};

class ComputeEnergy{

    int data_penalty_gray(Coord coordL, Coord coordR, const Image& left, const Image& right);

    int data_panalty_color(Coord coordL, Coord coordR, const Image& left, const Image& right);

    int smoothness_penalty_gray(Coord coordP1, Coord coordP2, int disp, const Image& left, const Image& right);

    int smoothness_penalty_color(Coord coordP1, Coord coordP2, int disp, const Image& left, const Image& right);

    int data_occlusion_penalty(Coord coordL, Coord coordR, const Image& left, const Image& right );

    int smoothness_penalty(Coord coordP1, Coord coordP2, int disp, const Image& left, const Image& right);
};

#endif //KOLMOGOROV_STEREO_COMPUTEENERGY_H
