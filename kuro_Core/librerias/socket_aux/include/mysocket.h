#ifndef MYSOCKET_H
#define MYSOCKET_H

#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

enum TCP_TYPE{
    SERVER,
    CLIENT
};
class MySocket
{
public:
    MySocket(TCP_TYPE tipo, int puerto=3333, string IP="127.0.0.1");
    bool Conectar();
    int SendData(char* data, int sizeData);
    int readData(char* data, int sizeData);

    void closeSock();
private:
    int sockfd, newsockfd, portno;
    socklen_t clilen;
    char buffer[5000];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
};

#endif // MYSOCKET_H
