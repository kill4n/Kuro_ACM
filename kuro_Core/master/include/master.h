#ifndef MASTER_H
#define MASTER_H
#include "perifericos/joystick/include/joystick_helper.h"
#include "cinematica/omni/include/omnimodel.h"
#include <stdio.h>

struct masterStr{
    int AxisDirec;
    int AxisVeloc;
};

class Master
{
public:
    Master();
    void inicializar();
    void conectar();
    joystick_helper *JoyH;
    OmniModel *OM;
private:

};

#endif // MASTER_H
