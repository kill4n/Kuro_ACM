#ifndef JOYSTICK_HELPER_H
#define JOYSTICK_HELPER_H

#include <linux/joystick.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#include "muramasa.h"

using namespace neko;

class joystick_helper
{
public:
    joystick_helper();
    int openJoy();
    int closeJoy();
    int startJoy();
private:
    int joy_fd, *axis=NULL,
        num_of_axis, num_of_buttons, x;
    char *button=NULL,
        name_of_joystick[80];
    struct js_event js;
};

#endif // JOYSTICK_HELPER_H
