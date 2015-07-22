#ifndef CTHREAD_H
#define CTHREAD_H
#include <pthread.h>
#include <iostream>

using namespace std;

class cThread
{
public:
    cThread(){}
    void create(){
        cout << "entre Thread "<< endl;
        pthread_create(&thread_id, NULL, &cThread::PrintHello, this);
        cout << "Creé Thread "<< endl;
        dat=0;
    }
    static void *PrintHello(void *d)
    {
        cThread *da=(cThread *)d;
        while(1)
            da->printMData();
        pthread_exit(NULL);
    }

    void printMData()
    {
        cout << "Hello World! Thread :" <<dat<< endl;
        dat++;
    }

private:
    pthread_t thread_id;
    int dat;
};

#endif // CTHREAD_H
