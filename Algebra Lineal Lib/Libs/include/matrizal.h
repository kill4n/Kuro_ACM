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
    //operadores
    MatrizAL &operator+(const MatrizAL& mat1);
    MatrizAL &operator-(const MatrizAL& mat1);
    MatrizAL &operator*(const MatrizAL& mat1);
    //auxiliares
    void Limpiar();
    void Identidad();
    void setData(int f, int c, double val);
    bool getDeterminante(double *det);
    //impresion
    const void Imprimir();
private:
    void initData();
    int _fila, _columna;
    double **data;
};
}
#endif // MATRIZAL_H
