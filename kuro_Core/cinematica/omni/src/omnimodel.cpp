#include "omnimodel.h"

OmniModel::OmniModel()
{
    printf("Creando modelo Omnidireccional\r\n");
}
void OmniModel::startModel()
{
    printf("iniciando omnidireccional\r\n");

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

OmniModel::~OmniModel()
{
    printf("Muriendo modelo Omnidireccional\r\n");
    stopModel();
    delete *ptrMDir;
    delete *ptrMRot;
}

void OmniModel::setSpeed(int goalSpeed)
{
    //printf("Definiendo velocidad = %d \r\n", goalSpeed);
    _speed = goalSpeed;
    for (int i = 0; i < numRuedas; ++i) {
        if (i%2)
            ptrMRot[i]->moveMotor(-goalSpeed);
        else
            ptrMRot[i]->moveMotor(goalSpeed);
    }
}

int OmniModel::getSpeed()
{
    return _speed;
}

void OmniModel::setDirection(int goalDir)
{
    //printf("Definiendo direccion = %d \r\n", goalDir);
    _direction = (goalDir*222)/1023;
    for (int i = 0; i < numRuedas; ++i) {
        ptrMDir[i]->moveMotor(_direction);
    }
}

int OmniModel::getDirection()
{
    return _direction;
}

void OmniModel::stopModel()
{
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->stopMotor();
        ptrMDir[i]->stopMotor();
    }    
}
