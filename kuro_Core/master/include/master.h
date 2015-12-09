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

enum MASTER_FLAGS{
    DISABLE_ALL         = 1 << 0, // binary 00000001
    ENABLE_CAMERA       = 1 << 1, // binary 00000010
    ENABLE_MOTORS       = 1 << 2, // binary 00000100
    ENABLE_JOYSTICK     = 1 << 3  // binary 00001000
};

class Master
{
public:
    Master();
    ~Master();
    void inicializar(int flags = DISABLE_ALL);
    void conectar();
    void moveRobot(int vel, int dir);
    void setMode(MODELO_TYPE config);

    joystick_helper *JoyH;
    CamaraController *camaraCon;
    ModeloInterface *MI;
private:
    int _flags;
    OmniModel OM;
    DiferModel DM;
    AckerModel AM;
    MODELO_TYPE _conf;
};

#endif // MASTER_H
