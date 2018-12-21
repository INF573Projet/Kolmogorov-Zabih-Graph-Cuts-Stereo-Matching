//
// Created by jiabin on 2018/12/18.
//

#ifndef KOLMOGOROV_STEREO_GRAPHCUT_H
#define KOLMOGOROV_STEREO_GRAPHCUT_H

#include "image.h"
#include "Configuration.h"
#include "maxflow/graph.h"
#include "ComputeEnergy.h"


class GraphCut {
public:
    GraphCut(Image left, Image right, Parameters p);
    ~GraphCut();

    void expansionMove(int alpha);

private:
    Image imgL;
    Image imgR;
    Coord imSizeL;
    Coord imSizeR;
    Parameters params;
    Mat conf_a; // matrix, shape = (w, h)
    Mat conf_b; // (w, h)
    Mat disparity; // (w, h)
    int totalEnergy;

    void build_data_term(Graph& g, Coord pixel, int alpha);

    void build_smoothness_term(Graph& g, Coord pixelL, Coord pixelR, int alpha);

    void build_uniqueness_term(Graph& g, Coord pixel, int alpha);




};


#endif //KOLMOGOROV_STEREO_GRAPHCUT_H
