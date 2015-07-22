#include "sockettest.h"

SocketTest::SocketTest(QObject *parent) : QObject(parent)
{

}

void SocketTest::Connect()
{
    socket = new QTcpSocket(this);
    //connected
    socket->connectToHost("192.168.0.180",2111);
    if (socket->waitForConnected(3000)) {
        qDebug() << "Conceted...";
        //sent
        //socket->write("SRi 01");
        //got

        //closed
        socket->close();
    }
    else
    {
        qDebug() << "Not Conected..";
    }
}
