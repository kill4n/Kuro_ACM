using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Motor3Control
{
    public class motor
    {
        private int _id;

        public int id
        {
            get { return _id; }
            set { _id = value; }
        }

        private int _velocidad;

        public int velocidad
        {
            get { return _velocidad; }
            set { _velocidad = value; }
        }

        private bool _sentido;

        public bool Sentido
        {
            get { return _sentido; }
            set { _sentido = value; }
        }

        private bool _freno;

        public bool freno
        {
            get { return _freno; }
            set { _freno = value; }
        }

        private int _rcvVel;

        public int rcvVel
        {
            get { return _rcvVel; }
            set { _rcvVel = value; }
        }

    }

    public class MotorEventArgs : EventArgs
    {
        public motor motorData = new motor();
        public MotorEventArgs(int vel, bool sen, bool fre, int ID)
        {
            motorData.velocidad = vel;
            motorData.Sentido = sen;
            motorData.freno = fre;
            motorData.id = ID;
        }

    }
}
