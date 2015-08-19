#ifndef KUROSOCKET_H
#define KUROSOCKET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class kuroSocket
{
public:
    kuroSocket(int port = 4050);
    char buffer[256];
    int getPuerto();
    int listenSock(int n);
    int sendSock();
    int readSock();
    int closeSock();
private:
    int _puerto;
    int sockfd, newsockfd;
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    int n;
};

#endif // KUROSOCKET_H
