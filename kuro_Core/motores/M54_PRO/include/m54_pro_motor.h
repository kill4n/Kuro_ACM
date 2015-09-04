#ifndef M54_PRO_MOTOR_H
#define M54_PRO_MOTOR_H

#include <stdio.h>

#include "motores/motorinterface/include/motorinterface.h"
#include "librerias/dynamixel_pro_aux/include/dynamixel.h"

namespace M54_PRO {

#define PORT "/dev/ttyUSB0"
using namespace Thor;

enum OPERATING_MODE_RW{
    TORQUE_CONTROL_MODE = 0, //0 : torque control mode: torque can be controlled in this mode; but not velocity nor position.
    VELOCITY_CONTROL_MODE = 1, //1 : velocity control mode: in this mode velocity and torque can be controlled; but not position.
    POSITION_CONTROL_MODE = 3, //3 : position control mode: in this mode position, velocity, and torque can be controlled.
    EXTENDED_CONTROL_MODE = 4  //4 : extended position control mode: in this mode position, velocity, and torque can be controlled. There is no position limit; multi-turn position control is enabled.
};
enum CONTROL_TABLE{
    ID_RW = 7,
    BAUD_RATE_RW = 8,
    OPERATING_MODE_RW = 11,
    MAX_POSITION_LIMIT_RW = 36,
    MIN_POSITION_LIMIT_RW = 40,
    TORQUE_ENABLED_RW = 562,
    GOAL_POSITION_RW = 596,
    GOAL_VELOCITY_RW = 600,
    GOAL_TORQUE_RW = 604,
    GOAL_ACCELERATION_RW = 606,
    MOVING_R = 610,
    PRESENT_POSITION_R = 611,
    PRESENT_VELOCITY_R = 615,
    PRESENT_CORRENT_R = 621,
    PRESENT_INPUT_VOLTAJE_R = 623,
    PRESENT_TEMPERATURE_R = 625
};
enum BAUD_RATE{
    BAUD_9600 = 0,
    BAUD_57600 = 1,
    BAUD_115200 = 2,
    BAUD_1Mbps = 3,
    BAUD_2Mbps = 4,
    BAUD_3Mbps = 5,
    BAUD_4Mbps = 6,
    BAUD_4_5Mbps = 7,
    BAUD_10_5Mbps = 8

};

class M54_PRO_Motor : public MotorInterface
{
public:
    M54_PRO_Motor(int id = 0, MOTOR_TYPE type = WHEEL);
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
    BAUD_RATE _baud_speed;

    Dynamixel *DXL;

};
void PrintCommStatus(int CommStatus);
void PrintErrorCode(int ErrorCode);

}
#endif // M54_PRO_H
