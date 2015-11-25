#ifndef MASTER_H
#define MASTER_H
#include "perifericos/joystick/include/joystick_helper.h"
#include "cinematica/omni/include/omnimodel.h"
#include "cinematica/difer/include/difermodel.h"
#include "cinematica/acker/include/ackermodel.h"
#include <stdio.h>

struct masterStr{
    int AxisDirec;
    int AxisVeloc;
};

class Master
{
public:
    Master(MODELO_TYPE config);
    void inicializar();
    void conectar();
    void moveRobot(int vel, int dir);
    joystick_helper *JoyH;
    ModeloInterface *MI;
private:
    OmniModel OM;
    DiferModel DM;
    AckerModel AM;
    MODELO_TYPE _conf;
};

#endif // MASTER_H
