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
    static void* readSick(void* csok);

    int sockfd, portno, n,timeRead,data[271];
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *buff;
    bool isConectado;

    pthread_t thread_id;
public:
    CSocket(string hostname = "192.168.0.180", int puerto = 2111);
    bool conectar();
    void SendMessage(string msg);
    void ReadMessage();
    void send_recv(string s);
    void close_conn();
    void setReadDataFunc(callback_function pFunc);
    void StartRead(int time_ms);
};

#endif // CSOCKET_H
