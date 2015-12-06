#include <iostream>
#include <fstream>
#include <signal.h>

#include "master.h"
#include "librerias/socket_aux/include/mysocket.h"

using namespace std;

JOY_STR joyGlob;

int isAlive = 1;
Master masterObject;
MySocket ms(SERVER, 2134);
Mat M(4,4, CV_8UC3, Scalar(0,0,255));

void JoystickActual(JOY_STR joyS)
{
    joyGlob = joyS;
}
void newFrameCallBack(bool isFrame, Mat imagen)
{
    startWindowThread();
    M = imagen;

}
void socketCallback(MensajesEventArgs e)
{
    printf("llego dato del cliente \r\n");
    char* daaa;
    int imgsize;
    switch (e._comando) {
    case 0x10:
        switch (e._datos[0]) {
        case 0x21:
            masterObject.setMode(OMNIDIRECCIONAL);
            break;
        case 0x22:
            masterObject.setMode(DIFERENCIAL);
            break;
        case 0x23:
            masterObject.setMode(ACKERMKAN);
            break;
        default:
            break;
        }
        break;

    case 0x11:
        M = (M.reshape(0,1));
        imgsize = M.total()*M.elemSize();
        printf("tamano a enviar [%d] {%d}\r\n",M.total(),M.elemSize());
        daaa= new char[1];
        daaa[0] = 0x13;
        ms.SendData(daaa,1);
        ms.SendData((char*)M.data,imgsize);
        break;
    default:
        break;
    }
}
void catch_close(int sig)
{
    printf("capture el errorr \r\n");
    isAlive = 0;
}
int main()
{
    int goalR = 0;
    int goalD = 0;
    signal(SIGINT, catch_close);
    cout << "Buen día, desde kuro!" << endl;
    //inicializar perifericos
    //            masterObject.setMode(OMNIDIRECCIONAL);

/*    masterObject.inicializar();
    masterObject.JoyH->setCallback(JoystickActual);
    masterObject.camaraCon->setCallback(newFrameCallBack);

    ms.setCallback(socketCallback);
    //correr hilos
    masterObject.conectar();
    ms.Conectar();
    ms.StartInternalThread();
    startWindowThread();
    //

    //

    //
    masterObject.setMode(OMNIDIRECCIONAL);*/
    //Ciclo Principal
    while (isAlive) {
        //goalD=(int)((joyGlob.AxisDir*1023)/32767);
        //goalR=(int)((joyGlob.AxisVel*1023)/32767);
        //masterObject.moveRobot(goalR, goalD);
        //cout<< M;
        /*imshow("lados",M);
        if (waitKey(1)>27) {
            break;
        }*/
    }
    printf("Saliendo del main\r\n");
    return 0;
}
