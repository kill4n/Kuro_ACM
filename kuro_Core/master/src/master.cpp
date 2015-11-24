#include "master.h"

Master::Master()
{
    printf("Bienvenido al robot kuro");
}

void Master::inicializar()
{
    printf("inicializando kuro ...");
    JoyH = new joystick_helper();
    JoyH->openJoy();
    OM = new OmniModel();
}

void Master::conectar()
{
    printf("joystick iniciado()");
    JoyH->StartInternalThread();
}



