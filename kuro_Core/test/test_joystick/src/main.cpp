#include <stdio.h>
#include "perifericos/joystick/include/joystick_helper.h"

void JoystickUpdate(JOY_STR joyS)
{
    printf("JoyUpdate V[%d] D[%d]                    \r",joyS.AxisVel, joyS.AxisDir);
}

int main()
{
    joystick_helper *JoyH= new joystick_helper();

    JoyH->openJoy();
    JoyH->setCallback(JoystickUpdate);
    /*while (1) {
        JoyH.readJoy();
    }*/
    JoyH->StartInternalThread();

    for (int i = 0; i < 10000000000; ++i);

    printf("\r\nFinall\r\n");
    for (int i = 0; i < 10000000000; ++i);
    printf("\r\nFinall2\r\n");

    delete JoyH;
    return 0;
}
