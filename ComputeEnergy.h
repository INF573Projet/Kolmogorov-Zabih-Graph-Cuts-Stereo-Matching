//
// Created by jiabin on 2018/12/18.
//

#ifndef KOLMOGOROV_STEREO_COMPUTEENERGY_H
#define KOLMOGOROV_STEREO_COMPUTEENERGY_H

struct Coord{
    Coord(int x, int y) : x(x), y(y) {}

    int x;
    int y; };

class ComputeEnergy{

    int data_penalty_gray(Coord coordL, Coord coordR);

    int data_panalty_color(Coord coordL, Coord coordR);

    int smoothness_penalty_gray(Coord coordP1, Coord coordP2, int disp);

    int smoothness_penalty_color(Coord coordP1, Coord coordP2, int disp);

    int data_occlusion_penalty(Coord coordL, Coord coordR);

    int smoothness_penalty(Coord coordP1, Coord coordP2, int disp);
};

#endif //KOLMOGOROV_STEREO_COMPUTEENERGY_H
