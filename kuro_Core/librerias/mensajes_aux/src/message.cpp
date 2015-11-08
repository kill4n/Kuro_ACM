#include "message.h"

using namespace neko;

Message::Message():
    ln("Mensajes")
{

}

void Message::decodeMesage(short *datos)
{
    m_CMD = (CMD_DT)datos[0];
    m_NumDat = datos[1];
    m_Datos = new short[m_NumDat];
    for (int i = 0; i < m_NumDat; ++i)
        m_Datos[i] = datos[i + 2];
    m_ChkSum = m_Datos[m_NumDat+2];
}

Message::~Message()
{
    delete[] m_Datos;
}
