#include "camaracontroller.h"
using namespace camara;
CamaraController::CamaraController(): _fps(30), _width(320), _height(240), isRunning(false), isRun(isRunning)
{
    printf("camara creada\r\n");
}

CamaraController::~CamaraController()
{
    isRunning = false;
    this->WaitForInternalThreadToExit();
    printf("Cerrando_hilo\r\n");
}

bool CamaraController::startCamara()
{
    _camera.open(0);
    if(!_camera.isOpened())
    {
        printf("ERROR: no se pudo aceder la camara o el video!\r\n");
        return false;
    }
    else {
        isRunning = true;
        printf("camara iniciada {%d}\r\n", isRunning);
        return true;
    }
}
bool CamaraController::stopCamera()
{
    isRunning=false;
}

void CamaraController::setCallback(void(*newFrameCallBack)(bool , Mat))
{
    callback = newFrameCallBack;
}

void CamaraController::InternalThreadEntry()
{
    while (isRunning) {
        if(_camera.isOpened())
        {
            _camera >> frame;
            this->callback(true, frame);
        }
        usleep(1000000/_fps);
    }
    _camera.release();
}

void CamaraController::setCameraResol(int width, int height)
{
    _width = width;
    _height = height;

    _camera.set(CV_CAP_PROP_FRAME_WIDTH, _width);
    _camera.set(CV_CAP_PROP_FRAME_HEIGHT, _height);
    printf("camara definida W[%d], H[%d]\r\n",_width,_height);
}

void CamaraController::setFPS(int fps)
{
    _fps = fps;
    printf("FPS definidos {%d}\r\n", _fps);
}

int CamaraController::getFPS()
{
    return _fps;
}
