#ifndef CAMARACONTROLLER_H
#define CAMARACONTROLLER_H

#include "opencv2/opencv.hpp"
#include "librerias/thread_aux/include/mythread.h"
#include <stdio.h>
#include <unistd.h>

namespace camara {

using namespace cv;

class CamaraController : public MyThread
{
public:
    CamaraController();
    ~CamaraController();
    bool startCamara();
    bool stopCamera();

    const bool& isRun;

    void setCallback(void (*newFrameCallBack)(bool , Mat));
    virtual void InternalThreadEntry();

    void setCameraResol(int width = 320, int height = 240);
    void setFPS(int fps = 30);
    int getFPS();

    void getResol(int &ancho, int &alto);
private:
    VideoCapture _camera;
    void (*callback)(bool , Mat);
    bool isRunning;
    int _width, _height;
    int _fps;

    int isData;
    Mat frame;
};
}
#endif // CAMARACONTROLLER_H
