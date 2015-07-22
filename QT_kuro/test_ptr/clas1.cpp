#include "clas1.h"

clas1::clas1(int x)
{
    dat =x;
}

void clas1::callClas2(void* other)
{
    dataClas2(this, other);
}

void clas1::setClas2Func(clas1::callback_function pFunc)
{
    this->dataClas2 = pFunc;
}

void clas1::setIntFcn(callback_int_function iiF)
{
    this->intF = iiF;
}

void clas1::callIntFu()
{
    this->intF(0);
}
