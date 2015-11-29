using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace noir_sim
{
    public class SickEventArgs : EventArgs
    {
        #region Variables
        private double[] _ang = new double[271];

        public double[] angulo
        {
            get { return _ang; }
            set { _ang = value; }
        }

        private String _data;

        public String data
        {
            get { return _data; }
            set { _data = value; }
        }

        private bool _init;

        public bool init
        {
            get { return _init; }
            set { _init = value; }
        }

        private float[] _dataRaw = new float[271];

        public float[] dataRaw
        {
            get { return _dataRaw; }
            set { _dataRaw = value; }
        }

        private double[] _dataY = new double[271];

        public double[] dataY
        {
            get { return _dataY; }
            set { _dataY = value; }
        }

        private double[] _dataX = new double[271];

        public double[] dataX
        {
            get { return _dataX; }
            set { _dataX = value; }
        }

        #endregion
     
        public SickEventArgs()
        {
            _init = true;
            _data = "";
            for (int i = 0; i < 271; i++)
            {
                _ang[i] = (double)(((i - 45) * Math.PI) / 180.0);
            }
        }

    }
}
