#include <stdio.h>
#include "librerias/socket_aux/include/mysocket.h"

int main()
{
    MySocket ms(SERVER,3344);

    ms.Conectar();
    char[] da= new char[5];
    da[0]=0x10;
    da[1]=0x20;
    da[2]=0x30;
    da[3]=0x40;
    da[4]=0x50;
    int sd=ms.SendData(da, sizeof(da));
    printf("datos enviados %d \r\r", sd);


    int rd= ms.readData(da,sizeof(da));
    printf("datos leidos %d-%d-%d-%d-%d \r\r", da[0],da[1],da[2],da[3],da[4]);


    //JoyH->StartInternalThread();

    for (int i = 0; i < 10000000000; ++i);

    printf("\r\nFinall\r\n");
    for (int i = 0; i < 10000000000; ++i);
    printf("\r\nFinall2\r\n");

    delete JoyH;
    return 0;
}
