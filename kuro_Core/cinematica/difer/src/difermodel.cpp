#include "difermodel.h"

DiferModel::DiferModel()
{    
    printf("Creando modelo Diferencial\r\n");
}
void DiferModel::startModel()
{
    printf("iniciando diferencial\r\n");
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

DiferModel::~DiferModel()
{
    printf("Muriendo modelo Diferencial\r\n");
    stopModel();
    delete *ptrMDir;
    delete *ptrMRot;
}

void DiferModel::setSpeed(int goalSpeed)
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

int DiferModel::getSpeed()
{
    return _speed;
}

void DiferModel::setDirection(int goalDir)
{
    //printf("Definiendo direccion = %d \r\n", goalDir);
    _direction = goalDir;
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->moveMotor(_direction);
    }
}

int DiferModel::getDirection()
{
    return _direction;
}

void DiferModel::stopModel()
{
    for (int i = 0; i < numRuedas; ++i) {
        ptrMRot[i]->stopMotor();
        ptrMDir[i]->stopMotor();
    }
}

