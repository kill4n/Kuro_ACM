#ifndef MAGIC_PIE_MOTOR_H
#define MAGIC_PIE_MOTOR_H

#include "motores/motorinterface/include/motorinterface.h"

namespace magic_pie {


class magic_pie_motor : public MotorInterface
{
public:
    magic_pie_motor(int id = 0, MOTOR_TYPE type = WHEEL);

    //funciones de la clase padre
    virtual void startMotor();
    virtual void moveMotor(double goal = 0);
    virtual void stopMotor();

    virtual double getPosition();
    //set get ID de motor
    virtual void setID(int id = 0);
    virtual int getID();
    //set get tipo de motor
    virtual void setType(MOTOR_TYPE type = WHEEL){}
    virtual MOTOR_TYPE getType(){return WHEEL;}
private:
    int _ID_motor;
    MOTOR_TYPE _motor;
};
}
#endif // MAGIC_PIE_MOTOR_H
