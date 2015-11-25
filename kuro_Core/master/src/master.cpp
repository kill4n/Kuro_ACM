#include "master.h"

Master::Master(MODELO_TYPE config):_conf(config)
{
    printf("Bienvenido al robot kuro");
    switch (config) {
    case OMNIDIRECCIONAL:
        MI = &OM;
        break;
    case DIFERENCIAL:
        MI = &DM;
        break;
    case ACKERMKAN:
        MI = &AM;
        break;
    default:
        MI = &DM;
        break;
    }
}

void Master::inicializar()
{
    printf("inicializando kuro ...");
    JoyH = new joystick_helper();
    JoyH->openJoy();
}

void Master::conectar()
{
    printf("joystick iniciado()");
    JoyH->StartInternalThread();
}

void Master::moveRobot(int vel, int dir)
{
    printf("DIR [%d],VEL[%d]            \r",dir,vel);

    switch (_conf) {
    case OMNIDIRECCIONAL:
        MI->setSpeed(vel);
        MI->setDirection(dir);
        break;
    case DIFERENCIAL:
        if ((dir == 0)) {
            MI->setSpeed(vel);
        }
        else
        {
            if((vel == 0)) {
                MI->setDirection(dir);
            }
            else {
                MI->setSpeed(0);
                MI->setDirection(0);
            }
        }
        break;
    case ACKERMKAN:
        MI->setSpeed(vel);
        MI->setDirection(dir);
        break;
    default:
        break;
    }
}
