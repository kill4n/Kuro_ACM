#include "kurosocket.h"


void error(const char *msg)
{
    perror(msg);
    exit(1);
}

kuroSocket::kuroSocket(int port):_puerto(port)
{
    //Crear y abrir el socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    //llener estructura del socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(_puerto);
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");
    printf("SocketCreado OK\r\n");
}

int kuroSocket::getPuerto()
{
    return _puerto;
}

int kuroSocket::listenSock(int n)
{
    listen(sockfd,n);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0)
        error("ERROR on accept");
}

int kuroSocket::sendSock()
{
    n = write(newsockfd,"I got your message",18);
    if (n < 0)
        error("ERROR writing to socket");
}

int kuroSocket::readSock()
{
    bzero(buffer,256);
    n = read(newsockfd,buffer,255);
    if (n < 0) error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
}

int kuroSocket::closeSock()
{
    close(newsockfd);
    close(sockfd);
}
