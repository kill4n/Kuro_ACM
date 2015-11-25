#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include "logneko.h"

namespace neko {
using namespace std;
class Message
{
public:
    Message();
    void decodeMesage(short *datos);
    ~Message();
private:
    CMD_DT m_CMD;
    short m_NumDat;
    short *m_Datos;
    short m_ChkSum;
    LogNeko ln;
};

}
#endif // MESSAGE_H
