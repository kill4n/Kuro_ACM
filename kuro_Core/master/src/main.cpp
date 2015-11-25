#include <iostream>
#include <fstream>

#include "master.h"

JOY_STR joyGlob;

Master M(OMNIDIRECCIONAL);
void JoystickActual(JOY_STR joyS)
{
    joyGlob = joyS;
}

using namespace std;   
int main()
{
    int goalR = 0;
    int goalD = 0;

    cout << "Buen día, desde kuro!" << endl;
    //inicializar perifericos
    M.inicializar();
    M.JoyH->setCallback(JoystickActual);
    //correr hilos
    M.conectar();

    //

    //

    //

    //

    //Ciclo Principal
    while (1) {
        goalD=(int)((joyGlob.AxisDir*1023)/32767);
        goalR=(int)((joyGlob.AxisVel*1023)/32767);
        M.moveRobot(goalR, goalD);
    }
    return 0;
}
