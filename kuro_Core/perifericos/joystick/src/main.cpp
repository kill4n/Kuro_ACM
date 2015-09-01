#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <linux/joystick.h>
#include <stdlib.h>


#include "joystick_helper.h"


int main()
{
    joystick_helper JoyH;

    JoyH.openJoy();

    return 0;
}
