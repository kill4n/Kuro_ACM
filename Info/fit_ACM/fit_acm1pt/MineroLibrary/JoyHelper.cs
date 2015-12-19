using OpenTK.Input;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading;

namespace MineroLibrary
{
    public class JoyHelper
    {
        public event JoystickHandler JoystickEvent;
        public delegate void JoystickHandler(object sender, JoystickEventArgs e);
        bool isRunning = false;
        BackgroundWorker bw;

        public JoyHelper()
        {
            bw = new BackgroundWorker();

            bw.DoWork += bw_DoWork;
        }

        public void conectar()
        {
            isRunning = true;
            bw.RunWorkerAsync();
        }

        public void desconectar()
        {
            isRunning = false;
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            while (isRunning)
            {
                Thread.Sleep(200);
                float x = 0, y = 0;
                for (int i = 0; i < 4; i++)
                {
                    var state = Joystick.GetState(i);
                    if (state.IsConnected)
                    {
                        x = state.GetAxis(JoystickAxis.Axis1);
                        y = state.GetAxis(JoystickAxis.Axis4);

                    }
                }
                if (JoystickEvent != null)
                    JoystickEvent(this, new JoystickEventArgs(x, y));
            }
        }
    }
    public class JoystickEventArgs : EventArgs
    {
        private float _axisV;
        public float axisVertical
        {
            get { return _axisV; }
        }

        private float _axisH;
        public float axisHorizontal
        {
            get { return _axisH; }
        }

        public JoystickEventArgs(float axis1, float axis2)
        {
            _axisV = axis1;
            _axisH = axis2;
        }
    }
}
