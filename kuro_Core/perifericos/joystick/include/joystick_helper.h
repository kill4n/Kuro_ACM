#ifndef JOYSTICK_HELPER_H
#define JOYSTICK_HELPER_H

#include <linux/joystick.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

#include "librerias/thread_aux/include/mythread.h"

#define JOY_DEV "/dev/input/js0"

struct JOY_STR{
    int AxisVel;
    int AxisDir;
};


class joystick_helper : public MyThread
{
public:
    joystick_helper();
    ~joystick_helper();
    int openJoy();
    int closeJoy();
    int readJoy();
    void setCallback(void (*cb)(JOY_STR));

    virtual void InternalThreadEntry();
private:
    bool isRunning;
    int joy_fd, *axis, num_of_axis, num_of_buttons, x;
    char *button, name_of_joystick[80];
    struct js_event js;

    struct JOY_STR joyAx;

    void (*callback)(JOY_STR);
};

#endif // JOYSTICK_HELPER_H
