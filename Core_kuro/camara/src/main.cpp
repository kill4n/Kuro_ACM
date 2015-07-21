#include <iostream>
#include "logneko.h"
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;
//using namespace neko;

int main(int, char **)
{
    VideoCapture camera;
    camera.open(0);
    if(!camera.isOpened())
    {
        cout << "ERROR: Could not access the camera or video!" << endl;
        return -1;
    }
    //Mat edges;//(100,100,CV_8UC3);
    //randu(edges,Scalar(0,0,0),Scalar(255,255,255));
    //imshow("imagen",edges);
    //waitKey(0);
    camera.set(CV_CAP_PROP_FRAME_WIDTH,640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    for (;;) {
        Mat frame;
        camera >> frame;
        imshow("color", frame);
        if (waitKey(30) >= 0) {
            break;
        }
    }
    return 0;
}

