#include "matrizal.h"
#include "alexception.h"

using namespace std;
using namespace AL;

MatrizAL::MatrizAL(int nxn):fila(&_fila),columna(&_columna)
{
    printf("Matriz cuadrada Creada %d x %d\r\n", nxn, nxn);
    _fila = nxn;
    _columna = nxn;
    initData();
}

MatrizAL::MatrizAL(int filas, int columnas):fila(&_fila),columna(&_columna)
{
    _fila = filas;
    _columna = columnas;
    initData();
}

MatrizAL::~MatrizAL()
{
    for (int i = 0; i < _fila; ++i) {
        delete [] data [i];
    }
    delete []data;
}

MatrizAL &MatrizAL::operator+(const MatrizAL &mat1)
{
    if ((this->_fila == mat1._fila)&&(this->_columna == mat1._columna)) {
        MatrizAL *resm = new MatrizAL(mat1._fila,mat1._columna);

        for (int i = 0; i < _fila; ++i) {
            for (int j = 0; j < _columna; ++j) {
                resm->data[i][j] = this->data[i][j] + mat1.data[i][j];
            }
        }
        return *resm;
    }else {
        throw ExceptionAL(ALERR_DIMENSIONES_NO_COINCIDEN);
    }
}

MatrizAL &MatrizAL::operator-(const MatrizAL &mat1)
{
    if ((this->_fila == mat1._fila)&&(this->_columna == mat1._columna)) {
        MatrizAL *resm = new MatrizAL(mat1._fila,mat1._columna);

        for (int i = 0; i < _fila; ++i) {
            for (int j = 0; j < _columna; ++j) {
                resm->data[i][j] = this->data[i][j] - mat1.data[i][j];
            }
        }
        return *resm;
    }else {
        throw ExceptionAL(ALERR_DIMENSIONES_NO_COINCIDEN);
    }
}

MatrizAL &MatrizAL::operator*(const MatrizAL &mat1)
{
    if(this->_columna == mat1._fila) {
        MatrizAL *resm = new MatrizAL(this->_fila,mat1._columna);

        for (int i = 0; i < this->_fila; ++i) {
            for (int k = 0; k < mat1._columna; ++k) {
                resm->data[i][k]=0;
                for (int j = 0; j < this->_columna; ++j) {
                    resm->data[i][k] += this->data[i][j] * mat1.data[j][k];
                }
            }
        }
        return *resm;
    }else {
        throw ExceptionAL(ALERR_DIMENSIONES_NO_COINCIDEN);
    }
}

void MatrizAL::Limpiar()
{
    for (int i = 0; i < _fila; ++i) {
        for (int j = 0; j < _columna; ++j) {
            data[i][j]=0;
        }
    }
}

void MatrizAL::Identidad()
{
    Limpiar();
    if (_fila==_columna) {
        for (int i = 0; i < _fila; ++i) {
            for (int j = 0; j < _columna; ++j) {
                if (j==i) {
                    data[i][j] = 1;
                } else {
                    data[i][j] = 0;
                }
            }
        }
    }
    else
    {
        throw ExceptionAL(ALERR_NO_CUADRADO);
    }
}

void MatrizAL::setData(int f, int c, double val)
{
    if((f<_fila)&&(c<_columna)){
        this->data[f][c] = val;
    }else {
        throw ExceptionAL(ALERR_FUERA_DE_RANGO);
    }
}

bool MatrizAL::getDeterminante(double *det)
{
    *det=0;
    if (this->_fila == this->_columna) {
        MatrizAL Md(_fila,2*_columna);
        for (int i = 0; i < _fila; ++i) {
            for (int j = 0; j < _columna; ++j) {
                Md.data[i][j] = data[i][j];
                Md.data[i][j+_columna] = data[i][j];
            }
        }
        double tmp,tmp2;
        for (int i = 0; i < _fila; ++i) {
            tmp=1;
            tmp2=1;
            for (int j = 0; j < _columna; ++j) {
                tmp*=Md.data[j][j + i];
                tmp2*=Md.data[j][((_columna *2)-1)-j - i];
            }
            *det+=tmp;
            *det-=tmp2;
        }
        return false;
    }
    else
    {
        return false;
    }
}

const void MatrizAL::Imprimir()
{
    for (int i = 0; i < _fila; ++i) {
        for (int j = 0; j < _columna; ++j) {
            cout<< data[i][j]<< " ";
        }
        cout <<endl;
    }
    cout <<endl;
}

void MatrizAL::initData()
{
    data = new double*[_fila];
    for (int i = 0; i < _fila; ++i) {
        data[i]= new double[_columna];
    }
    Limpiar();
}
