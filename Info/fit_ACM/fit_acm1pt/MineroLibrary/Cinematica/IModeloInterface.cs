using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MineroLibrary
{
    public enum MODELO_TYPE
    {
        OMNIDIRECCIONAL = 0x21,
        DIFERENCIAL = 0x22,
        ACKERMKAN = 0x23
    };

    public interface IModeloInterface
    {
        void setDeviceIndex(int devInd);
        void startModel();
        void setSpeed(int goalSpeed);
        int getSpeed();
        void setDirection(int goalDir);
        int getDirection();
        void stopModel();

        bool isStarted();
    }
}
