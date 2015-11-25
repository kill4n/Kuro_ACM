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

short *MiMensaje::encodeMensaje()
{
    short * datos = new short[m_NumDat + 3];

    datos[0] = m_CMD;
    short chkSM = m_CMD;
    datos[1] = m_NumDat;
    chkSM += datos[1];
    for (int i = 0; i < m_NumDat; ++i) {
        datos[i+2]= m_Datos[i];
        chkSM += m_Datos[i];
    }
    datos[m_NumDat+2]=chkSM^m_CMD;
}
