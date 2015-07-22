#include <QCoreApplication>
//#include "sockettest.h"
#include <iostream>

#include "csocket.h"
#include "cthread.h"

#include <pthread.h>


using namespace std;
CSocket cSock("192.168.0.180", 2111);

//Apuntador a Funcion

void my_callbak_func(int*dat)
{
    printf( "HOla desde main \r\n" );
    for (int i = 0; i < 271; ++i) {
        printf("%4d ", dat[i]);
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    printf("hola mundo\r\n");
    void (*pcalbak)(int*) = my_callbak_func;
    cSock.setReadDataFunc(pcalbak);
    cSock.conectar();

    cSock.StartRead(10);
    while(1);

    return a.exec();
}
