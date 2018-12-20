//
// Created by jiabin on 2018/12/18.
//

#include "GraphCut.h"

GraphCut::GraphCut(const Image<uchar>& left, const Image<uchar>& right, int alpha, Configuration& f, Parameters& p) {
    imgL = left;
    imgR = right;
    this->alpha = alpha;
    this->f = f;
    params = p;

}

GraphCut::~GraphCut() {

}

void GraphCut::build_data_term(Coord pixel) {

}

void GraphCut::expansionMove(Configuration &new_f) {
    new_f = Configuration(imgL, -1);
}

Graph<short,short,int> &GraphCut::buildGraph() {
    //TODO change
    Graph<short, short, int> g(0,0);
    return g;
}

void GraphCut::build_smothness_term(Coord pixelL, Coord pixelR) {

}

void GraphCut::build_uniqueness_term(Coord pixel) {

}


