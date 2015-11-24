#include "mysocket.h"

MySocket::MySocket(TCP_TYPE tipo, int puerto, string IP)
{
    portno = puerto;
    if(tipo == SERVER)
    {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            cout<<"ERROR opening socket";
        bzero((char *) &serv_addr, sizeof(serv_addr));
        portno = puerto;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);
        if (bind(sockfd, (struct sockaddr *) &serv_addr,
                 sizeof(serv_addr)) < 0)
            printf("ERROR on binding");
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
        //error("ERROR on accept");
        return false;
    }
    return true;
}

void MySocket::closeSock()
{
    close(newsockfd);
    close(sockfd);
}

int MySocket::SendData(char* data, int sizeData){
    int n = write(newsockfd,data,sizeData);
    if (n < 0) printf("ERROR writing to socket");
    return n;
}

int MySocket::readData(char* data, int sizeData){
    int n = read(newsockfd,data,sizeData);
    if (n < 0) printf("ERROR reading from socket");
    printf("Here is the message: %s\n",data);
    return n;
}
