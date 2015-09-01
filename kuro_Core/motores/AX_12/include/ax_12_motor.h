#ifndef AX_12_MOTOR_H
#define AX_12_MOTOR_H

#include "./motores/motorinterface/include/motorinterface.h"
#include "librerias/dynamixel_aux/include/dynamixel.h"

#include <stdio.h>
namespace AX_12 {

enum CONTROL_TABLE{
    ID_RW = 3,
    BAUD_RATE_RW = 4,
    CW_ANGLE_LIMIT_L_RW = 6,
    CW_ANGLE_LIMIT_H_RW = 7,
    CCW_ANGLE_LIMIT_L_RW = 8,
    CCW_ANGLE_LIMIT_H_RW = 9,
    TORQUE_ENABLED_RW = 18,
    GOAL_POSITION_L_RW = 30,    //GOAL POSITION
    GOAL_POSITION_H_RW = 31,    //GOAL POSITION
    MOVING_SPEED_L_RW = 32,     //GOAL SPEED
    MOVING_SPEED_H_RW = 33,     //GOAL SPEED
    PRESENT_POSITION_L_R = 36,
    PRESENT_POSITION_H_R = 37,
    PRESENT_SPEED_L_R = 38,
    PRESENT_SPEED_H_R = 39
};

enum BAUD_RATE{
    BAUD_1Mbps = 1,
    BAUD_500Kbps = 3,
    BAUD_400Kbps = 4,
    BAUD_250Kbps = 7,
    BAUD_200Kbps = 9,
    BAUD_115200 = 16,
    BAUD_57600 = 34,
    BAUD_19200 = 103,
    BAUD_9600 = 207
};

class AX_12_Motor : public MotorInterface
{
public:
    AX_12_Motor(int id = 0, MOTOR_TYPE type = WHEEL);
    void setBaudSpeed(BAUD_RATE br = BAUD_1Mbps);
    //funciones de la clase padre
    virtual void startMotor();
    virtual void moveMotor(double goal = 0);
    virtual void stopMotor();

    virtual double getPosition();
    //set get ID de motor
    virtual void setID(int id = 0);
    virtual int getID();
    //set get tipo de motor
    virtual void setType(MOTOR_TYPE type = WHEEL);
    virtual MOTOR_TYPE getType();

private:
    int _ID_motor;
    MOTOR_TYPE _motor;
    int _deviceIndex;
    BAUD_RATE _baud_speed;
};

}
#endif // AX_12_MOTOR_H
