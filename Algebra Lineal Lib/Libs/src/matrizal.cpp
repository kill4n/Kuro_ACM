#include "matrizal.h"
using namespace std;
using namespace AL;

MatrizAL::MatrizAL(int nxn):fila(&_fila),columna(&_columna)
{
    printf("Matriz cuadrada Creada %d x %d\r\n", nxn, nxn);
    _fila = nxn;
    _columna = nxn;
//    initData();
}

MatrizAL::MatrizAL(int filas, int columnas):fila(&_fila),columna(&_columna)
{
    _fila = filas;
    _columna = columnas;
    initData();
}

MatrizAL::~MatrizAL()
{
    delete data;
}

const void MatrizAL::imprimir()
{
    for (int i = 0; i < _fila; ++i) {
        for (int j = 0; j < _columna; ++j) {
            cout<< data[i][j]<< " ";
        }
        cout <<endl;
    }
}

void MatrizAL::initData()
{
    *data = new double[_fila];
    for (int i = 0; i < _fila; ++i) {
        data[i]= new double[_columna];
    }
}

