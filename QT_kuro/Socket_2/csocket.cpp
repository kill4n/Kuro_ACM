#include "csocket.h"

CSocket::CSocket(string hostname, int puerto)
{    
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
}

bool CSocket::conectar()
{
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
void CSocket::SendMessage(string msg)
{
    string str = "@", end = "@";
    str[0] = 2; end[0] = 3;

    string dat = str + msg + end;

    buff = new char[5000];
    strcpy(buff, dat.c_str());

    n = write(sockfd,buff,dat.length());
    if (n < 0)
        cout << "ERROR writing to socket" <<endl;
    else
        cout << "Escritura Correcta.." <<endl;
}
void CSocket::ReadMessage()
{
    bzero(buff,5000);
    n = read(sockfd,buff,5000);
    if (n < 0)
        cout<<"ERROR reading from socket"<<endl;
    //else
    //printf("Datos recibidos: %d XXXDDD\n",n);
    if(isConectado)
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
        dataReadFunc(data);
    }
}
void CSocket::send_recv(string s)
{
    SendMessage(s);
    ReadMessage();
}
void CSocket::close_conn()
{
    close(sockfd);
    isConectado = false;
}
void CSocket::setReadDataFunc(CSocket::callback_function pFunc)
{
    dataReadFunc = pFunc; // store
}
void CSocket::StartRead(int time_ms)
{
    timeRead = time_ms*1000;
    pthread_create(&thread_id, NULL, &CSocket::readSick, this);
}
void *CSocket::readSick(void *csok)
{
    while (1)
    {
        ((CSocket*)csok)->ReadMessage();
        usleep(((CSocket*)csok)->timeRead);
    }
    return NULL;
}
