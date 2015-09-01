#ifndef KIN_OMNI_H
#define KIN_OMNI_H

class Kin_Omni
{
public:
    Kin_Omni();
    //Setters
    void setVel_Lin(double Vel_Lin);
    void setVelAng(double Vel_Ang);
    void setTs(double Tiempo_s);
    //Getters
    double getPosX()const;
    double getPosY()const;
    double getAng()const;
    //Otros
    void Move();

private:
    double k_Xp,k_Yp,k_Thp;
    double k_Vel_lin,k_Vel_ang;
    double k_Ts;
};

#endif // KIN_OMNI_H
