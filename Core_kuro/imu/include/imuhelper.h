#ifndef IMUHELPER_H
#define IMUHELPER_H

class imuHelper
{
public:
    imuHelper();
    double getAcc() const;
private:
    double i_AccX, i_AccY, i_AccZ;
    double i_GyrX, i_GyrY, i_GyrZ;
    double i_MagX, i_MagY, i_MagZ;
};

#endif // IMUHELPER_H
