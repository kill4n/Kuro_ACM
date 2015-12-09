#include "master.h"

Master::Master():_conf(DIFERENCIAL)
{
    printf("Bienvenido al robot kuro\r\n");
}

Master::~Master()
{
    printf("Master muriendo...\r\n");
    delete JoyH;
    delete MI;
    delete camaraCon;
}

void Master::inicializar(int flags)
{
    _flags = flags;
    printf("inicializando kuro ...\r\n");
    if(flags & ENABLE_JOYSTICK)
    {
        printf("Iniciando joystick ...\r\n");
        JoyH = new joystick_helper();
        JoyH->openJoy();
    }
    if(flags & ENABLE_CAMERA)
    {
        printf("Iniciando camara ...\r\n");
        camaraCon = new CamaraController();
        camaraCon->setFPS(100);
        camaraCon->setCameraResol();
        camaraCon->startCamara();
    }
    if(flags & ENABLE_MOTORS)
    {
        printf("Iniciando motores q...\r\n");
        setMode(_conf);
        printf("Fin inicio motores ...\r\n");
    }
}

void Master::conectar()
{
    if (_flags & ENABLE_JOYSTICK) {
        JoyH->StartInternalThread();
        printf("joystick conectado\r\n");
    }
    if(_flags & ENABLE_CAMERA)
    {
        camaraCon->StartInternalThread();
        printf("camara conectada\r\n");
    }
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

void Master::setMode(MODELO_TYPE config)
{
    if (MI!=NULL)
    {MI->stopModel();
    }
    _conf= config;
    switch (_conf) {
    case OMNIDIRECCIONAL:
        printf("Cambio modo a OMNIDIRECCIONAL\r\n");
        MI = &OM;
        break;
    case DIFERENCIAL:
        printf("Cambio modo a DIFERENCIAL\r\n");
        MI = &DM;
        break;
    case ACKERMKAN:
        printf("Cambio modo a ACKERMKAN\r\n");
        MI = &AM;
        break;
    default:
        MI = &DM;
        break;
    }
    MI->startModel();
}
