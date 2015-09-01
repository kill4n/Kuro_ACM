#ifndef SICK_TEST_H
#define SICK_TEST_H

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
// Macros make the call much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.6
#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))
template <class T>
class sick_test
{
private:
    // Typedefs make this much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.5
    typedef void (T::*SickCallback)(int*);
    SickCallback sc;
    T *t1;

    int sockfd, portno, n,timeRead,*data;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char *buff;
    bool isConectado;
    void* parent0;

    pthread_t thread_id;
public:
    sick_test(string hostname = "192.168.0.180", int puerto = 2111){
        isConectado=false;
        isCon = &isConectado;
        portno = puerto;

        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            cout<<"ERROR abriendo socket"<<endl;
        server = gethostbyname(hostname.c_str());

        if (server == NULL) {
            fprintf(stderr,"ERROR, no hay host\n");
            exit(0);
        }
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr,
              (char *)&serv_addr.sin_addr.s_addr,
              server->h_length);
        serv_addr.sin_port = htons(portno);
        cout << "socket Creado." <<endl;
        data= new int[271];
    }
    const bool *isCon;
    bool conectar(){
        printf("Iniciando Conexion\r\n");
        if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
        {
            cout<<"ERROR connecting"<<endl;
            return false;
        }
        else
        {
            send_recv("sRI 0");
            send_recv("sEI 76 1");
            send_recv("sRI 152");
            send_recv("sEI 62 1");
            send_recv("sRI E7");
            send_recv("sEI 59 1");
            send_recv("sRI DD");
            send_recv("sEI 55 1");

            cout << "Conectado" <<endl;
            isConectado = true;
            return true;
        }
    }
    void setCallback(SickCallback SickActivado, T& t)
    {
        printf("Set sick Activado\r\n");
        sc = SickActivado;
        t1 = &t;
    }
    void callExt(int * d)
    {
        CALL_MEMBER_FN(*t1, sc)(d);
    }

    void SendMessage(string msg){
        string str = "@", end = "@";
        str[0] = 2; end[0] = 3;

        string dat = str + msg + end;

        buff = new char[5000];
        strcpy(buff, dat.c_str());

        n = write(sockfd,buff,dat.length());
        if (n < 0)
            cout << "ERROR writing to socket" <<endl;
        /*else
            cout << "Escritura Correcta.." <<endl;*/
    }
    void ReadMessage(){
        bzero(buff,5000);
        n = read(sockfd,buff,5000);
        if (n < 0)
            cout<<"ERROR reading from socket"<<endl;
       /* else
            printf("Datos recibidos: %d XXXDDD\n",n);*/
        if(isConectado == true)
        {
            char *token;
            /* get the first token */
            token = strtok(buff, " ");
            int i=0;
            /* walk through other tokens */
            while(token != NULL)
            {
                if( (i>=26) && (i<=26+270))
                {
                    data[i-26] = (int)strtol(token, NULL, 16);
                }
                token = strtok(NULL, " ");
                i++;
            }
            //dataReadFunc(this, parent0);
            if (i>300)
            {                
                callExt(data);
            }
        }
    }
    void send_recv(string s)
    {
        SendMessage(s);
        ReadMessage();
    }
    void close_conn()
    {
        close(sockfd);
        isConectado = false;
    }

    void StartRead(int time_ms)
    {
        timeRead = time_ms*1000;
        pthread_create(&thread_id, NULL, &sick_test::readSick, this);
    }

    int *getData()
    {
        printf("dataSc:%d \r\n",data[0]);
        return data;
    }
    static void* readSick(void* csok)
    {
        while (1)
        {
            ((sick_test*)csok)->ReadMessage();
            usleep(((sick_test*)csok)->timeRead);
        }
        return NULL;
    }
    //void setReadDataFunc(callback_function pFunc,void* toEvent);

};

#endif // SICK_TEST_H
