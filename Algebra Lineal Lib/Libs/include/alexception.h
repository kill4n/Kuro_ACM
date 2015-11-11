#ifndef ALEXCEPTION
#define ALEXCEPTION
#include <exception>

namespace AL
{
using namespace std;

enum ALERROR{
    ALERR_DEFAULT,
    ALERR_NO_CUADRADO,
    ALERR_DIMENSIONES_NO_COINCIDEN,
    ALERR_FUERA_DE_RANGO
};

class ExceptionAL : exception
{
public:
    ExceptionAL():erroral(ALERR_DEFAULT){}
    ExceptionAL(ALERROR erral):erroral(erral) {}
    virtual const char* what() const throw()
    {
        switch (erroral) {
        case ALERR_NO_CUADRADO:
            return "La matriz no es cuadrada\r\n";
        case ALERR_DIMENSIONES_NO_COINCIDEN:
            return "Las dimensiones de las matrices no coinciden para la operación\r\n";
        case ALERR_FUERA_DE_RANGO:
            return "Dato fuera de los rangos de la matriz\r\n";
        default:
            return "Hola Default\r\n";
        }
    }

private:
    ALERROR erroral;
};

}
#endif // ALEXCEPTION
