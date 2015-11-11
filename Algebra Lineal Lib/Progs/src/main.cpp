#include <stdio.h>
#include <iostream>

#include "matrizal.h"
#include "alexception.h"

using namespace std;
using namespace AL;

int main (void){
    MatrizAL M1(3), M2(3);
    M2.Identidad();
    printf("Hola desde Main0\r\n");
    try {
        MatrizAL M =M1+M2;
        M.Imprimir();
        M = M+M2;
        M.Imprimir();
        M = M+M2;
        M.Imprimir();

        MatrizAL M3(3,3);
        M3.setData(0,0,1);
        M3.setData(1,0,2);
        M3.setData(2,0,2);
        M3.setData(0,1,2);
        M3.setData(1,1,1);
        M3.setData(2,1,0);
        M3.setData(0,2,3);
        M3.setData(1,2,-1);
        M3.setData(2,2,5);
        M.Imprimir();
        M3.Imprimir();
        M=M*M3;
        M.Imprimir();
        double deet;
        M3.Imprimir();
        M3.getDeterminante(&deet);
        printf("det: %f \r\n", deet);
    }
    catch(ExceptionAL& e) {
        cout << e.what() << endl;
    }
    return 0;
}
