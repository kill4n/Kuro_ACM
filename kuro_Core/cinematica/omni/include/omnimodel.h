#ifndef OMNIMODEL_H
#define OMNIMODEL_H

#include "motores/motorinterface/include/motorinterface.h"
#include "motores/AX_12/include/ax_12_motor.h"
using namespace AX_12;
using namespace std;

#define numRuedas 6
#define DEVICE_INDEX 0

class OmniModel
{
public:
    OmniModel();
    void setSpeed(int goalSpeed);
    int getSpeed();

    void setDirection(int goalDir);
    int getDirection();

    void stopModel();
private:
    MotorInterface *ptrMRot[numRuedas];
    MotorInterface *ptrMDir[numRuedas];
    AX_12_Motor ax12_Rot[numRuedas];
    AX_12_Motor ax12_Dir[numRuedas];
    int _speed, _direction;
};

#endif // OMNIMODEL_H
