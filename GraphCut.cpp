//
// Created by jiabin on 2018/12/18.
//

#include <mpif-sizeof.h>
#include "GraphCut.h"
#include "maxflow/graph.h"


GraphCut::GraphCut(const Image<uchar>& left, const Image<uchar>& right, int alpha, Configuration& f, Parameters& p) {
    imgL = left;
    imgR = right;
    alpha = alpha;
    f = f;
    params = p;
}

const struct Coord NEIGHBORS[] = { Coord(-1,0), Coord(0,1) }; // neighbours points
typedef int node_id;
static const node_id VAR_ALPHA = ((node_id)-1); // this value indicates that (o, p+alpha) is already activate
static const node_id VAR_ABSENT = ((node_id)-2); // this value indicates that (p, p+d) is not added in graph
const int OCCLUDED = std::numeric_limits<int>::max();
inline bool IS_VAR(node_id var) { return (var>=0); }


GraphCut::~GraphCut() {
    free(&imgL);
    free(&imgR);
    free(&conf_a);
    free(&conf_b);
    free(&disparity);
}

void GraphCut::build_data_term(Graph& g, Coord pixel, int alpha) {
    int d = disparity.at<uchar>(pixel.y, pixel.x);
    Coord q = pixel+d;
    node_id id;
    if(alpha==d) { // active assignment (p,p+a) in A^a will remain active
        conf_a.at<int>(pixel.y, pixel.x) = VAR_ALPHA;
        conf_b.at<int>(pixel.y, pixel.x) = VAR_ALPHA;
        totalEnergy+=(data_occlusion_penalty(pixel,q, imgL, imgR));
        return;
    }

    if(d!=OCCLUDED){
        // In this case, pixel p is active with a disparity
        // d different from alpha, so add two nodes
        id = g.add_node();
        g.add_tweights(id, 0, data_occlusion_penalty(pixel,q, imgL, imgR));
        conf_b.at<int>(pixel.y, pixel.x) = id;
    }else{
        conf_b.at<int>(pixel.y, pixel.x) = VAR_ABSENT;
    }

    q = pixel+a;
    // If the current active disparity differs from alpha,
    // we must add (p, p+alpha) in graph
    if(inRect(q, imSizeR)){
        id = g.add_node();
        g.add_tweights(id, data_occlusion_penalty(pixel,q, imgL, imgR), 0);
        conf_a.at<int>(pixel.y, pixel.x) = id;
    }else{
        conf_a.at<int>(pixel.y, pixel.x) = VAR_ABSENT;
    }

}



void GraphCut::build_smoothness_term(Graph& g, Coord pixelL, Coord pixelR, int alpha) {

}

void GraphCut::build_uniqueness_term(Graph& g, Coord pixel, int alpha) {


}

GraphCut::GraphCut(Image left, Image right, Parameters p) {
    imgL = left;
    imgR = right;
    imSizeL = Coord(imgL.cols, imgL.rows);
    imSizeR = Coord(imgR.cols, imgR.rows);
    params = p;
    conf_a = Mat(left.rows, left.cols, CV_32S);
    conf_b  = Mat(left.rows, left.cols, CV_32S);
    disparity = Mat(left.rows, left.cols, CV_8U);
    totalEnergy = 0;


}

void GraphCut::expansionMove(int alpha) {

    Graph<short,short,int> g(2*imgL.rows*imgL.cols, 12*imgL.rows*imgL.cols);
    totalEnergy = 0;
    RectIterator endL=rectEnd(imSizeL);
    for(RectIterator p=rectBegin(imSizeL); p!=endL; ++p)
        build_data_term(g, *p, alpha);

    for(RectIterator p1=rectBegin(imSizeL); p1!=endL; ++p1)
        for(unsigned int k=0; k<2; k++) {
            Coord p2 = *p1+NEIGHBORS[k];
            if(inRect(p2,imSizeL))
                build_smoothness_term(g, *p1, p2, alpha);
        }

    for(RectIterator p=rectBegin(imSizeL); p!=endL; ++p)
        build_uniqueness_term(g, *p, alpha);


}


