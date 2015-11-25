#include "mimensaje.h"

MiMensaje::MiMensaje()
{
}

void MiMensaje::decodeMensaje(short *datos)
{
    m_CMD = datos[0];
    m_NumDat = datos[1];
    m_Datos = new short[m_NumDat];
    for (int i = 0; i < m_NumDat; ++i)
        m_Datos[i] = datos[i + 2];
    m_ChkSum = m_Datos[m_NumDat+2];
}
