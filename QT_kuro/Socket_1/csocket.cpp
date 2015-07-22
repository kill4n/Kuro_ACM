#include "csocket.h"


CSocket::CSocket(string hostname, int puerto)
{    
    portno = puerto;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        cout<<"ERROR opening socket"<<endl;
    server = gethostbyname(hostname.c_str());

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
    cout << "socket Creado." <<endl;
}

bool CSocket::conectar()
{
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

        return true;
    }
}

void CSocket::SendMessage(string msg)
{
    string str = "@";
    string end = "@";
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

    string ddd(buff);

    char s[2] = " ";
    char *token;

    /* get the first token */
    token = strtok(buff, s);
    int i=0,j=0;
    int d;
    int datt[271];
    /* walk through other tokens */
    while(token != NULL)
    {
        if( (i >= 25) && (i<=30) )
        {
           d = (int)strtol(token, NULL, 16);
            //printf( "dat Ini: %s Pos: %d double %f len(%d) \r\n", token , i, d, strlen(token));
        }

        if( (i >= (291)) && (i<=(296)) )
        {
           d = (int)strtol(token, NULL, 16);
            //printf( "dat fin: %s Pos: %d double %f len(%d) \r\n", token ,i, d, strlen(token));
        }
        if( (i>=26) && (i<=26+270))
        {
            data[i-26] = (int)strtol(token, NULL, 16);
            //printf("%4d ", datt[i-26]);
            j++;
        }

        token = strtok(NULL, s);
        i++;
    }
    //data = datt;
    cout <<endl;
    printf("Numero de datoos en array: {%d} \r\n",j);
    printf("daa sock %4d ", data[0]);
    dataReadFunc(data);
    /*dataString(buff);* /
    1
    printf("%s\n",ddd.c_str());*/
}

void CSocket::send_recv(string s)
{
    SendMessage(s);
    ReadMessage();
}

void CSocket::close_conn()
{
    close(sockfd);
}

char *CSocket::getData()
{
    if (strlen(this->buff)>0) {
        dataReadFunc(data);
    }
}

void CSocket::setReadDataFunc(CSocket::callback_function pFunc)
{
    dataReadFunc = pFunc; // store
}

void CSocket::setReadString(CSocket::calback_string pString)
{
    dataString = pString;
}
