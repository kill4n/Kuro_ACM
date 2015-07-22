#include <QCoreApplication>
//#include "sockettest.h"
#include <iostream>

#include "csocket.h"
#include "cthread.h"

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
CSocket cSock("192.168.0.180", 2111);

//Apuntador a Funcion

void my_callbak_func(int*dat)
{
    printf( "HOla desde main \r\n" );
    for (int i = 0; i < 271; ++i) {
        printf("%4d ", dat[i]);
    }
}


void my_callback_string(char* dat)
{
    cout << "data callback:" << dat<<endl;
}

void* readSick(void* unused)
{
    while (1)
    {
        cSock.ReadMessage();

        usleep(10*1000);
    }
    return NULL;
}

/* Prints x’s to stderr. The parameter is unused. Does not return. */
void* print_xs (void* unused)
{
    while (1)
    {
        fputc ('x', stderr);
        usleep(1000000);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    void (*pcalbak)(int*) = my_callbak_func;
    cSock.setReadDataFunc(pcalbak);
    cSock.setReadString(&my_callback_string);
    cSock.conectar();

    pthread_t thread_id;
    pthread_create(&thread_id, NULL, &readSick, NULL);

/*    string sTestSplit="hola mundo 123";

    cout << "texto test: " << sTestSplit.c_str() <<endl;
    char str[80] = "This is - www.tutorialspoint.com - website";
    char s[2] = " ";
    char *token;
* /
    /* get the first token * /
    //token = strtok(str, s);

    /* walk through other tokens * /
  /*  while( token != NULL )
    {
        printf( "%s\n", token );

        token = strtok(NULL, s);
    }
* /

    //  cSock.close_conn();
    //    SocketTest cTest;
    //    cTest.Connect();
    /*
    cout << "Hello World!" << endl;
    string one = "#";
    string two = "sRI 00 1";
    string tre = "$";
    one[0] = 2; tre[0] = 3;
    cout << "one_len: " << one.length() <<endl;
    cout << "two_len: " << two.length() <<endl;
    cout << "three_len: " << tre.length() <<endl;
    string dat = one + two + tre;
    cout << "dat_len: " << dat.length() <<endl;
    cout << "data: " << dat.c_str() <<endl;
    char *x= new char[50];
    strcpy (x, dat.c_str());
    cout << "datx: " << (int)x[0] <<endl;


    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];

    portno = 2111;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        cout<<"ERROR opening socket"<<endl;
    server = gethostbyname("192.168.0.180");

    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        cout<<"ERROR connecting"<<endl;
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);
    n = write(sockfd,buffer,strlen(buffer));
    if (n < 0)
        cout<<"ERROR writing to socket"<<endl;
    bzero(buffer,256);
    n = read(sockfd,buffer,255);
    if (n < 0)
        cout<<"ERROR reading from socket"<<endl;
    printf("%s\n",buffer);
    close(sockfd);
* /
    /*cThread th;
    cout<<"hoila main"<<endl;
    th.create();
*/
    //while (1)
    {
        fputc ('ox', stderr);
        sleep(5);
    }
    return a.exec();
}
