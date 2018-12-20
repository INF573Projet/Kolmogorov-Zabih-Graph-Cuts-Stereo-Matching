//
// Created by leon on 12/19/18.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "image.h"
#include "Configuration.h"
#include "StereoMatching.h"

using namespace cv;
using namespace std;

int main() {
    /* Read images */
    cout << "Hello, World!" << endl;
    Image<Vec3b> img = Image<Vec3b> (imread("../images/left.png"));
    imshow("Input", img);
    waitKey(0);
    Image<uchar> imgL = img.greyImage();
    Image<uchar> imgR = img.greyImage();

    /* Creating the StereoMatching object */
    int minDisp = -4;
    int maxDisp = 8;
    int K = -1;
    int lambda1 = -1;
    int lambda2 = -1;
    int edgeThresh = 8;
    int maxIter = 4;
    int denominator = 8;
    bool is_L2 = true;
    StereoMatching graphCut(minDisp, maxDisp, maxIter, is_L2, denominator, edgeThresh, K, lambda1, lambda2);

    /* Compute disparity */
    Image<short> disparity;
    graphCut(imgL, imgR, disparity);
    cout << disparity << endl;
    imshow("disparity", StereoMatching::dispImage(disparity));
    waitKey(0);

    return 0;
}