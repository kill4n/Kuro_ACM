#include <iostream>
#include <stdio.h>
#include "wheel.h"

using namespace std;

int main()
{
    cout << "Programa Control Ruedas" << endl;
    Wheel R1, R2;

    R1.setVelocidad(12);
    R2.setVelocidad(23);

    printf("vel r1 = %f \r\n",R1.getVelocidad());
    printf("vel r2 = %f \r\n",R2.getVelocidad());

    return 0;
}
