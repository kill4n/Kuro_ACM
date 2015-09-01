#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <stdlib.h>


#include "perifericos/joystick/include/joystick_helper.h"


int main()
{
    joystick_helper JoyH;

    JoyH.openJoy();
    while (1) {
        JoyH.readJoy();
    }
    JoyH.closeJoy();
    return 0;
}
