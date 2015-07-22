#ifndef SALIDA_H
#define SALIDA_H

#include <iostream>
#include <stdio.h>

using namespace std;

class Salida
{
public:
    Salida();
    void SecondTriggered(int x)
    {
        cout << "Laser class respondio. " << x << endl;
    }
};

#endif // SALIDA_H
