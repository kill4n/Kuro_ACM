#include <QCoreApplication>

#include "clas1.h"
#include "clas2.h"
#include "stdio.h"
#include <iostream>

class Fred{
public:
    int d;
    Fred(int a)
    {
        d=a;
    }

    int f(char x, float y)
    {
        printf("{%c},{%f}\r\n",x,y*d);
        return 0;
    }

    int g(char x, float y);
    int h(char x, float y);
    int i(char x, float y);
};

using namespace std;

typedef int (Fred::*FredMemFn)(char x, float y);
#define CALL_MEMBER_FN(object,ptrToMember) ((object).*(ptrToMember))


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Fred f2(2),f3(10);
    clas1 c1(20);
    clas2 c2;

    FredMemFn p = &Fred::f;
    CALL_MEMBER_FN(f2,p)('c',12);

    ((f3).*(p))('d',14);


    c1.setClas2Func(clas2::metod);
    c1.callClas2(&c2);
    cout << "dC2: " << c2.y <<endl;


    c1.callIntFu();
    cout << "ddC2: " << c2.y <<endl;
    return a.exec();
}
