#include <iostream>
#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

void newFoto(Mat ima)
{
    imshow("color", ima);
}

int main(int, char**)
{
    VideoCapture cap(0); // open the default camera
    if(!cap.isOpened())  // check if we succeeded
        return -1;
    //namedWindow("edges",1);
    Mat edges(100,100, CV_8UC3, Scalar(255,0,0));
    //imshow("rand",edges);
    cout << "M = "<< endl << " "  << edges << endl << endl;
    waitKey(0);
    //namedWindow("edges",1);
    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera
        cvtColor(frame, edges, CV_BGR2GRAY);
        GaussianBlur(edges, edges, Size(7,7), 1.5, 1.5);
        Canny(edges, edges, 0, 30, 3);
        imshow("edges", edges);
        newFoto(frame);
        if(waitKey(30) >= 0) break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
