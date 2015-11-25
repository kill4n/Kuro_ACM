#ifndef MYETHERNET_H
#define MYETHERNET_H

#include "librerias/socket_aux/include/mysocket.h"
#include "librerias/mensajes_aux/include/mimensaje.h"

class MyEthernet
{
public:
    MyEthernet();
private:
    MySocket *sockServidor;
    MiMensaje *mensaje;
};

#endif // MYETHERNET_H
