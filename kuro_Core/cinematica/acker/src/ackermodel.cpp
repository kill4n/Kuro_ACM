#include "ackermodel.h"

AckerModel::AckerModel()
{    
    printf("iniciando omni\r\n");
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i] = &ax12_Rot[i];
        ptrMDir[i] = &ax12_Dir[i];
        ax12_Dir[i].setDeviceID(DEVICE_INDEX);
        ax12_Rot[i].setDeviceID(DEVICE_INDEX);
        ax12_Dir[i].setBaudSpeed(BAUD_1Mbps);
        ax12_Rot[i].setBaudSpeed(BAUD_1Mbps);
    }

    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->setID(i+7);
        ptrMRot[i]->startMotor();
        ptrMRot[i]->setType(WHEEL);

        ptrMDir[i]->setID(i+1);
        ptrMDir[i]->startMotor();
        ptrMDir[i]->setType(JOINT);
    }
    setSpeed(0);
    setDirection(0);
}

AckerModel::~AckerModel()
{
    stopModel();
}

void AckerModel::setSpeed(int goalSpeed)
{
    //printf("Definiendo velocidad = %d \r\n", goalSpeed);
    _speed = goalSpeed;
    for (int i = 0; i < numRuedas; ++i) {
        if (i%2)
            ptrMRot[i]->moveMotor(-_speed);
        else
            ptrMRot[i]->moveMotor(_speed);
    }
}

int AckerModel::getSpeed()
{
    return _speed;
}

void AckerModel::setDirection(int goalDir)
{
    //printf("Definiendo direccion = %d \r\n", goalDir);
    _direction = (goalDir*111)/1023;
    ptrMDir[0]->moveMotor(_direction);
    ptrMDir[1]->moveMotor(_direction);

    ptrMDir[4]->moveMotor(-_direction);
    ptrMDir[5]->moveMotor(-_direction);
}

int AckerModel::getDirection()
{
    return _direction;
}

void AckerModel::stopModel()
{
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->stopMotor();
        ptrMDir[i]->stopMotor();
    }
    delete *ptrMDir;
    delete *ptrMRot;
}
