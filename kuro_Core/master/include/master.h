#ifndef MASTER_H
#define MASTER_H
#include "perifericos/joystick/include/joystick_helper.h"
#include "cinematica/omni/include/omnimodel.h"
#include "cinematica/difer/include/difermodel.h"
#include "cinematica/acker/include/ackermodel.h"
#include "sensores/camara/include/camaracontroller.h"
#include <stdio.h>
using namespace camara;

struct masterStr{
    int AxisDirec;
    int AxisVeloc;
};

class Master
{
public:
    Master();
    ~Master();
    void inicializar();
    void conectar();
    void moveRobot(int vel, int dir);
    void setMode(MODELO_TYPE config);

    joystick_helper *JoyH;
    CamaraController *camaraCon;
    ModeloInterface *MI;
private:
    OmniModel OM;
    DiferModel DM;
    AckerModel AM;
    MODELO_TYPE _conf;
};

#endif // MASTER_H
