#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
public:
    Wheel();
    double getVelocidad()const;
    void setVelocidad(double velocidad);
private:
    double w_Velocidad;
    bool w_Sentido;
    bool w_Freno;
    bool w_Crusero;
};

#endif // WHEEL_H
