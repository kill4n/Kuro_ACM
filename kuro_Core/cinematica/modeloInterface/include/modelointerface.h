#ifndef MODELOINTERFACE_H
#define MODELOINTERFACE_H

enum MODELO_TYPE{
    OMNIDIRECCIONAL,
    DIFERENCIAL,
    ACKERMKAN
};

class ModeloInterface
{
public:
    virtual ~ModeloInterface(){}
    virtual void startModel() = 0;
    virtual void setSpeed(int goalSpeed) = 0;
    virtual int getSpeed() = 0;
    virtual void setDirection(int goalDir) = 0;
    virtual int getDirection() = 0;
    virtual void stopModel() = 0;
};

#endif // MODELOINTERFACE_H
