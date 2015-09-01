#include "kin_ack.h"
using namespace std;

Kin_Ack::Kin_Ack(double _Largo, double _Ancho) : k_Phi(0), Phi(k_Phi),
    k_Largo(_Largo), Largo(k_Largo), k_Ancho(_Ancho), Ancho(k_Ancho),
    k_X(0), PosX(k_X), k_Y(0), PosY(k_Y),
    k_Theta(0), Ang(k_Theta), k_Xrp(0), Vel_Lin(k_Xrp),
    k_Ts(0.01){
    _th = new double[2];
    _Xw = new double[2];
    _Yw = new double[2];
    for (int i = 0; i < 2; ++i) {
        _th[i] = 0;
        _Xw[i] = 0;
        _Yw[i] = 0;
    }
}
// Metodos Set
void Kin_Ack::setLargo(double _Largo){
    this->k_Largo = _Largo;
}
void Kin_Ack::setAncho(double _Ancho){
    this->k_Ancho = _Ancho;
}
void Kin_Ack::setVel_Lin(double _Vel_Lin){
    this->k_Xrp = _Vel_Lin;
}
void Kin_Ack::setPhi(double _Phi, bool _deg){
    if (!_deg) {
        this->k_Phi = _Phi;
    }
    else{
        this->k_Phi = _Phi*M_PI/180.0;
    }
}
//Mover el carro
void Kin_Ack::Mover(){
    k_Xp = cos(k_Theta)*k_Xrp;
    k_Yp = sin(k_Theta)*k_Xrp;
    k_Thp = (tan(k_Phi)/k_Largo)*k_Xrp;
    //Calculos Integrales
    CalcularIntegralZoh(_th, k_Thp);
    CalcularIntegralZoh(_Xw, k_Xp);
    CalcularIntegralZoh(_Yw, k_Yp);
    //Actualizar Registros
    _th[1] = _th[0];k_Theta = _th[0];
    _Xw[1] = _Xw[0];k_X = _Xw[0];
    _Yw[1] = _Yw[0];k_Y = _Yw[0];
    t += k_Ts;
    printf("X: %.14f Y: %.14f Th: %.14f Time: %.3f \r\n", this->k_X, this->k_Y, this->k_Theta, this->t);
}
void Kin_Ack::CalcularIntegralZoh(double *Sal, double Ent)
{
    Sal[0] = (Ent*k_Ts) + Sal[1];
}
