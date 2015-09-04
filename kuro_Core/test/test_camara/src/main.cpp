#include <iostream>
#include "sensores/camara/include/camaracontroller.h"


/*****************
 *
 * Revisar hilo en la captura de imagen si no
 * hacerlo como una clase sin hilo
 * ya me mame de esto.
 *
 * ****************************/




using namespace std;
using namespace camara;

Mat M(4,4, CV_8UC3, Scalar(0,0,255));

void newFrameCallBack(bool isFrame, Mat imagen)
{    
    printf("funcion vuelta {%d}\r\n",isFrame);
    M = imagen;
}

int main(int, char **)
{
    printf("hola mundo \r\n");

    CamaraController *camaraCon = new CamaraController();
    camaraCon->setCameraResol(640, 480);
    camaraCon->startCamara();
    camaraCon->setCallback(newFrameCallBack);
    camaraCon->StartInternalThread();

    for (int i = 0; i < 100000000000; ++i)
    {
        imshow("salida2",M);
        waitKey(0);
    }

    printf("\r\nFinall\r\n");

    printf("\r\nFinall2\r\n");

    delete camaraCon;
    return 0;
}



