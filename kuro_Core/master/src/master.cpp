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

Master::~Master()
{
    delete JoyH;
    delete MI;
    delete camaraCon;
}

void Master::inicializar()
{
    printf("inicializando kuro ...\r\n");
    JoyH = new joystick_helper();
    JoyH->openJoy();
    camaraCon = new CamaraController();
    camaraCon->setFPS(100);
    camaraCon->startCamara();
}

void Master::conectar()
{
    JoyH->StartInternalThread();
    printf("joystick conectado\r\n");
    camaraCon->StartInternalThread();
    printf("camara conectada\r\n");

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
