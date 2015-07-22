#include <iostream>
#include "laser.h"
#include <salida.h>
using namespace std;

int main()
{
    Laser<Salida> l;
    Salida s;
    cout << "Hello World 00!" << endl;
    l.setCallback(&Salida::SecondTriggered, s);
    cout << "Hello World 10!" << endl;
    l.StartLaser();
    for(int j=0;j<100000000;j++);
    cout << "Hello World 01!" << endl;

    return 0;
}


/*
#include <iostream>

// Macros make the call much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.6
#define CALL_MEMBER_FN(object, ptrToMember) ((object).*(ptrToMember))
template <class T>
class Second
{
public:
    Second() {}
    // Typedefs make this much more readable: http://www.parashift.com/c++-faq-lite/pointers-to-members.html#faq-33.5
    typedef void (T::*SecondTriggeredCallback)(void);

    // You'll also need an *instance* of the "T" class
    Second(SecondTriggeredCallback SecondTriggered, T& t)
    {
        CALL_MEMBER_FN(t, SecondTriggered)();
    }

    void CallFirst(SecondTriggeredCallback SecondTriggered, T& t)
    {
        CALL_MEMBER_FN(t, SecondTriggered)();
    }
};

class First
{
public:
    int d;
    First(int s)
        :second(NULL)
    {
        std::cout << "first class was created" << std::endl;
        second = new Second<First>(&First::SecondTriggered, *this);
        d=s;
    }

    ~First()
    {
        delete second;
    }

    void SecondTriggered()
    {
        std::cout << "second class was created and responded: " << d << std::endl;
    }

private:
    First(const First&);
    First& operator =(const First&);
    Second<First>* second;
};

int main()
{
    First first(2);
    Second<First> s;
    first.d=5;
    s.CallFirst(&First::SecondTriggered, first);
}
*/
