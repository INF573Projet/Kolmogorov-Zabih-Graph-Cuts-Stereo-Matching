#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "image.h"

using namespace cv;
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    Image<Vec3b> img = Image<Vec3b> (imread("../images/left.png"));
    cout << img << endl;
    imshow("Input", img);
    waitKey(0);

    return 0;
}

