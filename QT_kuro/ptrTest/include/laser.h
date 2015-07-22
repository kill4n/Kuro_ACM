#ifndef LASER_H
#define LASER_H

#include <stdio.h>
#include <iostream>

// Macros make the call much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.6
#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))
template <class T>
class Laser
{
public:
    Laser(){}
    // Typedefs make this much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.5
    typedef void (T::*SecondTriggeredCallback)(int);
    void setCallback(SecondTriggeredCallback SecondTriggered, T& t)
    {
        printf("Set Triger\r\n");
        st = SecondTriggered;
        t1 = &t;
        //CALL_MEMBER_FN(t, SecondTriggered)();
    }
    int l =1;
    void callExt()
    {
        CALL_MEMBER_FN(*t1, st)(10-l);
        ((*t1).*(st))(l++);
    }

    /*void CallExtern(SecondTriggeredCallback SecondTriggered, T& t)
    {
        CALL_MEMBER_FN(t, SecondTriggered)();
    }*/

    void StartLaser(){
        for (int i = 0; i < 10; ++i) {
            printf("Hola Mundo \r\n");
            for(int j=0;j<100000000;j++);
            callExt();
        }
    }
    int readData(int);
private:
    SecondTriggeredCallback st;
    T *t1;
};

#endif // LASER_H
