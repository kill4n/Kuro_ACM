#include <iostream>
#include "sensores/camara/include/camaracontroller.h"

using namespace std;
using namespace camara;

Mat M(4,4, CV_8UC3, Scalar(0,0,255));
CamaraController *camaraCon;

void newFrameCallBack(bool isFrame, Mat imagen)
{
    startWindowThread();
    M = imagen;
}

int main(int, char **)
{
    printf("hola mundo \r\n");
    camaraCon = new CamaraController();
    camaraCon->setFPS(100);
    camaraCon->startCamara();
    camaraCon->setCallback(newFrameCallBack);
    camaraCon->StartInternalThread();
    startWindowThread();

    while(camaraCon->isRun)
    {
        imshow("salida",M);
        if(waitKey(1)>27)
            break;
    }

    printf("\r\nFinalizo\r\n");

    delete camaraCon;
    return 0;
}
