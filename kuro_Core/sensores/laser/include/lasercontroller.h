#ifndef LASERCONTROLLER_H
#define LASERCONTROLLER_H

#include "librerias/thread_aux/include/mythread.h"

class LaserController : public MyThread
{
public:
    LaserController();
    ~LaserController();
    //metodo virtual thread
    virtual void InternalThreadEntry();

private:

};

#endif // LASERCONTROLLER_H
