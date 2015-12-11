using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace fit_acm1pt
{
    public enum MODELO_TYPE
    {
        OMNIDIRECCIONAL,
        DIFERENCIAL,
        ACKERMKAN
    };

    interface IModeloInterface
    {
        void startModel();
        void setSpeed(int goalSpeed);
        int getSpeed();
        void setDirection(int goalDir);
        int getDirection();
        void stopModel();
    }
}
