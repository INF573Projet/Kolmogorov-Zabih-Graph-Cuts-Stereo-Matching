//
// Created by leon on 12/19/18.
//

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "image.h"
#include "Configuration.h"

using namespace cv;
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Image<Vec3b> img = Image<Vec3b> (imread("../images/left.png"));
    imshow("Input", img);
    waitKey(0);

    cout << img.size << endl;

    Image<uchar> grayImg = img.greyImage();

    Configuration f(grayImg);
    cout << f(Coord(383, 287), OCCLUDED::value) << endl;

    return 0;
}