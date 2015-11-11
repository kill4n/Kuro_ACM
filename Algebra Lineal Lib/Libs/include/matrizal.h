#ifndef MATRIZAL_H
#define MATRIZAL_H

#include <iostream>



namespace AL {

class MatrizAL
{
public:    
    MatrizAL(int nxn);
    MatrizAL(int filas, int columnas);
    ~MatrizAL();
    const int *fila;
    const int *columna;

    const void imprimir();
private:
    void initData();
    int _fila, _columna;
    double **data;
};
}
#endif // MATRIZAL_H
