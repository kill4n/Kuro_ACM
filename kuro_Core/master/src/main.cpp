#include <iostream>
#include <fstream>

#include "master.h"

JOY_STR joyGlob;

masterStr masterData;
Master M;
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
        goalD=(int)((joyGlob.AxisDir*222)/32767);
        goalR=(int)((joyGlob.AxisVel*1023)/32767);
        printf("dir [%d],vel[%d]            \r",goalD,goalR);
        M.OM->setSpeed(goalR);
        M.OM->setDirection(goalD);

    }
    return 0;
}
