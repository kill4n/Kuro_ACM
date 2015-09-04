#include "camaracontroller.h"
using namespace camara;
CamaraController::CamaraController(): _fps(30), _width(320), _height(240)
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

void CamaraController::setCallback(void(*newFrameCallBack)(bool , Mat))
{
    callback = newFrameCallBack;
    printf("Definida llamada de Callback\r\n");
}

void CamaraController::InternalThreadEntry()
{
    printf("Hola 0 desde Hilo {%d}\r\n",isRunning);
    while (isRunning) {
        printf("Hola 0 desde Hilo {%d}\r\n",isRunning);
        if(_camera.isOpened())
        {
            _camera >> frame;
            printf("hay frame \r\n");
            this->callback(true, frame);
        }
        else
        {
            Mat M(20,20, CV_8UC3, Scalar(125,125,255));
            this->callback(false, M);
        }
        usleep(1000000/_fps);
    }
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

