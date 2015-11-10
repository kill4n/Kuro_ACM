#include "mysocket.h"

MySocket::MySocket(TCP_TYPE tipo, int puerto=3333, String IP="127.0.0.1")
{
    portno = puerto;
    if(tipo == SERVER)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            error("ERROR opening socket");
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = atoi(argv[1]);
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);
        if (bind(sockfd, (struct sockaddr *) &serv_addr,
                 sizeof(serv_addr)) < 0)
            error("ERROR on binding");
    }
}

bool MySocket::Conectar()
{
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsockfd = accept(sockfd,
                       (struct sockaddr *) &cli_addr,
                       &clilen);
    if (newsockfd < 0)
    {
        error("ERROR on accept");
        return false;
    }
    return true;
}

void MySocket::closeSock()
{
    close(newsockfd);
    close(sockfd);
}

int SendData(char* data, int sizeData){
    n = write(newsockfd,data,sizeData);
    if (n < 0)
        error("ERROR writing to socket");
    return n;
}

int readData(char* data, int sizeData){
    n = read(newsockfd,data,sizeData);
    if (n < 0)
        error("ERROR reading from socket");
    printf("Here is the message: %s\n",buffer);
    return n;
}
