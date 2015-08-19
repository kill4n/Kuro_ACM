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
    cv::Mat image;

    namedWindow("Output Window");
    camera.set(CV_CAP_PROP_FRAME_WIDTH,640);
    camera.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    for (;;) {
        /*Mat frame;
        camera >> frame;
        imshow("Output Window", frame);
        if (waitKey(30) >= 0) {
            break;
        }*/
        if(!camera.read(image)) {
            std::cout << "No frame" << std::endl;
            cv::waitKey();
        }
        cv::imshow("Output Window", image);
        // encode mat to jpg and copy it to content
        std::vector<uchar> buf;
        cv::imencode(".jpg", image, buf, std::vector<int>());
        std::string content(buf.begin(), buf.end()); //this must be sent to the client

        if(cv::waitKey(1) >= 0) break;
    }
    return 0;
}



