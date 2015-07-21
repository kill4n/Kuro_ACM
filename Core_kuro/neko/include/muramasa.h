#ifndef MURAMASA_H
#define MURAMASA_H

#define _USE_MATH_DEFINES

#include <math.h>

namespace neko {

#define LOG_NAME "Log_Neko.log"
#define MEMORY_NUM 25

enum STATUS{
    NK_OK = 0,
    NK_ERROR = 104
};

enum CMD_DT{
    CMD_SEND = 0x10
};

static double De2Rad(double _degr)
{
    return _degr*M_PI/180.0;
}

static double Rad2Deg(double _rad)
{
    double rd=_rad*180.0/M_PI;
    return rd;
}

}
#endif //MURAMASA_H
