#ifndef JOYSTICK_HELPER_H
#define JOYSTICK_HELPER_H

#include <linux/joystick.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#define JOY_DEV "/dev/input/js0"

class joystick_helper
{
public:
    joystick_helper();
    int openJoy();
    int closeJoy();
    int readJoy();
private:
    int joy_fd, *axis=NULL,num_of_axis, num_of_buttons, x;
    char *button=NULL, name_of_joystick[80];
    struct js_event js;
};

#endif // JOYSTICK_HELPER_H
