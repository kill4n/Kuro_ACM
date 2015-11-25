#include <iostream>
#include <fstream>

#include "master.h"

JOY_STR joyGlob;

Master masterObject(ACKERMKAN);
void JoystickActual(JOY_STR joyS)
{
    joyGlob = joyS;
}
Mat M(4,4, CV_8UC3, Scalar(0,0,255));
void newFrameCallBack(bool isFrame, Mat imagen)
{
    startWindowThread();
    M = imagen;
}

using namespace std;   
int main()
{
    int goalR = 0;
    int goalD = 0;

    cout << "Buen día, desde kuro!" << endl;
    //inicializar perifericos
    masterObject.inicializar();
    masterObject.JoyH->setCallback(JoystickActual);
    masterObject.camaraCon->setCallback(newFrameCallBack);
    //correr hilos
    masterObject.conectar();
    startWindowThread();
    //

    //

    //

    //Ciclo Principal
    while (1) {
        goalD=(int)((joyGlob.AxisDir*1023)/32767);
        goalR=(int)((joyGlob.AxisVel*1023)/32767);
        masterObject.moveRobot(goalR, goalD);
        cout<< M;
    }
    return 0;
}
