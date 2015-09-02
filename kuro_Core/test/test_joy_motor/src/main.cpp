#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "motores/motorinterface/include/motorinterface.h"
#include "motores/AX_12/include/ax_12_motor.h"
#include "perifericos/joystick/include/joystick_helper.h"

using namespace AX_12;
using namespace std;

JOY_STR joyGlob;

void JoystickUpdate(JOY_STR joyS)
{
    joyGlob= joyS;
}

#define numRuedas 6
int main()
{
    joystick_helper *JoyH= new joystick_helper();
    JoyH->openJoy();
    JoyH->setCallback(JoystickUpdate);

    MotorInterface *ptrMRot[numRuedas];
    MotorInterface *ptrMDir[numRuedas];
    AX_12_Motor ax12_Rot[numRuedas];
    AX_12_Motor ax12_Dir[numRuedas];

    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i] = &ax12_Rot[i];
        ptrMDir[i] = &ax12_Dir[i];
    }

    int goalR = 0;
    int goalD = 0;
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->setID(i+7);
        ptrMRot[i]->startMotor();
        ptrMRot[i]->setType(WHEEL);

        ptrMDir[i]->setID(i+1);
        ptrMDir[i]->startMotor();
        ptrMDir[i]->setType(JOINT);
    }

    JoyH->StartInternalThread();

    while(1)
    {
        goalD=(int)((joyGlob.AxisDir*222)/32767);
        goalR=(int)((joyGlob.AxisVel*1023)/32767);
        printf("dir [%d],vel[%d]            \r",goalD,goalR);
        /*printf("Definir Angulo -222,222 \r");
        printf( "Press Enter key to continue!(press ESC and Enter to quit)\n" );
        if(getchar() == 0x1b)
            break;
        //set wheel mode
        */
        //printf( "Succeed to set wheel mode\n" );
        for (int i = 0; i < numRuedas; ++i) {

            if (i%2)
                ptrMRot[i]->moveMotor(-goalR);
            else
                ptrMRot[i]->moveMotor(goalR);
            ptrMDir[i]->moveMotor(goalD);
        }
    }

    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->stopMotor();
        ptrMDir[i]->stopMotor();
    }
    delete JoyH;
    printf( "Press Enter key to terminate...\n" );
    getchar();
    return 0;
}
