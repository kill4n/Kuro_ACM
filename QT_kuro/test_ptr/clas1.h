#ifndef CLAS1_H
#define CLAS1_H

class clas1
{
private:
    typedef void (*callback_function)(void*,void*); // type for conciseness
    callback_function dataClas2; // variable to store function pointer type

public:
    typedef void (*callback_int_function)(int); // type for conciseness
    callback_int_function intFcn;

    int dat;
    clas1(int x);
    void callClas2(void *other);
    void setClas2Func(callback_function pFunc);


    callback_int_function intF;
    void setIntFcn(callback_int_function iiF);
    void callIntFu();
};

#endif // CLAS1_H
