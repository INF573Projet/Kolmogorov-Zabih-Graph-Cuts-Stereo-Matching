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

    GraphCut(const Image<uchar>& left, const Image<uchar>& right, int alpha, Configuration& f, Parameters& p);

    ~GraphCut();

    void expansionMove(int alpha);

private:

    
    Coord imSizeL;
    Coord imSizeR;

    Graph<short,short,int> g;
    Image<uchar> imgL;
    Image<uchar> imgR;
    int alpha;
    Configuration f;

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
