#ifndef CSOCKET_H
#define CSOCKET_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <pthread.h>

using namespace std;

class CSocket
{
private:
    typedef void (*callback_function)(int*); // type for conciseness
    callback_function dataReadFunc; // variable to store function pointer type
    typedef void (*calback_string)(char*);
    calback_string dataString;

    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *buff;
    bool isConectado;


public:
    CSocket(string hostname = "192.168.0.180", int puerto = 2111);
    bool conectar();
    void SendMessage(string msg);
    void ReadMessage();
    void send_recv(string s);
    void close_conn();
    char* getData();
    void setReadDataFunc(callback_function pFunc);
    void setReadString(calback_string pString);
    int data[271];
};

#endif // CSOCKET_H
