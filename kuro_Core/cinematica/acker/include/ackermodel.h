#ifndef ACKERMODEL_H
#define ACKERMODEL_H

#include "motores/motorinterface/include/motorinterface.h"
#include "motores/AX_12/include/ax_12_motor.h"
#include "cinematica/modeloInterface/include/modelointerface.h"

using namespace AX_12;
using namespace std;

#define numRuedas 6
#define DEVICE_INDEX 0

class AckerModel : public ModeloInterface
{
public:
    AckerModel();
    ~AckerModel();
    virtual void startModel();
    virtual void setSpeed(int goalSpeed);
    virtual int getSpeed();

    virtual void setDirection(int goalDir);
    virtual int getDirection();

    virtual void stopModel();
private:
    MotorInterface *ptrMRot[numRuedas];
    MotorInterface *ptrMDir[numRuedas];
    AX_12_Motor ax12_Rot[numRuedas];
    AX_12_Motor ax12_Dir[numRuedas];
    int _speed, _direction;
};

#endif // ACKERMODEL_H
