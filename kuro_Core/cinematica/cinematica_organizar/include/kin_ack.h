#ifndef KIN_ACK_H
#define KIN_ACK_H

#include <math.h>
#include <stdio.h>
#include <iostream>
#include "muramasa.h"

class Kin_Ack
{
public:
    Kin_Ack(double _Largo, double _Ancho);
    //setters
    void setLargo(double _Largo);
    void setAncho(double _Ancho);
    void setVel_Lin(double _Vel_Lin);
    void setPhi(double _Phi, bool _deg);
    //getters
    const double &Phi;
    const double &Largo;
    const double &Ancho;
    const double &PosX;
    const double &PosY;
    const double &Ang;
    const double &Vel_Lin;
    //metodos
    void Mover();
private:
    void CalcularIntegralZoh(double *Sal, double Ent);
    double k_Xrp, k_Phi;
    double k_Largo, k_Ancho;
    double k_X, k_Y, k_Theta;
    double k_Xp, k_Yp, k_Thp;
    double *_th, *_Xw, *_Yw;
    double k_Ts, t;
};

#endif // KIN_ACK_H
