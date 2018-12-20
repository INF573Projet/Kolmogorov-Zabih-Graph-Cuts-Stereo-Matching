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
    GraphCut(const Image<uchar>& left, const Image<uchar>& right, int alpha, Configuration& f, Parameters& p);
    ~GraphCut();

    void expansionMove(Configuration& new_f);

private:
    Graph<short,short,int> g;
    Image<uchar> imgL;
    Image<uchar> imgR;
    int alpha;
    Configuration f;
    Parameters params;

    Graph<short,short,int>& buildGraph();

    void build_data_term(Coord pixel);

    void build_smothness_term(Coord pixelL, Coord pixelR);

    void build_uniqueness_term(Coord pixel);




};


#endif //KOLMOGOROV_STEREO_GRAPHCUT_H
