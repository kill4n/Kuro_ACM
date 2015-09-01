#ifndef MOTORINTERFACE_H
#define MOTORINTERFACE_H

enum MOTOR_TYPE{
    JOINT,
    WHEEL
};
//Abstract Class MotorInterface
class MotorInterface
{
public:
    //Pure virtual functions
    virtual void startMotor() = 0;
    virtual void moveMotor(double id = 0) = 0;
    virtual void stopMotor() = 0;

    virtual double getPosition() = 0;

    virtual void setID(int id = 0) = 0;
    virtual int getID() = 0;

    virtual void setType(MOTOR_TYPE type = WHEEL) = 0;
    virtual MOTOR_TYPE getType() = 0;
};

#endif // MOTORINTERFACE_H
