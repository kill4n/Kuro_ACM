#ifndef MIMENSAJE_H
#define MIMENSAJE_H

class MiMensaje
{
public:
    MiMensaje();
    void decodeMensaje(short *datos);
    short *encodeMensaje();
private:
    short m_CMD;
    short m_NumDat;
    short *m_Datos;
    short m_ChkSum;
};

#endif // MIMENSAJE_H
