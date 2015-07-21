#include "wheel.h"

Wheel::Wheel()
{
    w_Velocidad = 0;
    w_Sentido = true;
    w_Freno = false;
    w_Crusero = false;
}

double Wheel::getVelocidad() const
{
    return w_Velocidad;
}

void Wheel::setVelocidad(double velocidad)
{
    w_Velocidad = velocidad;
}
