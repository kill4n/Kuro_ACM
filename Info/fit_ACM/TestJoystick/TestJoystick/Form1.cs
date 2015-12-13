using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using OpenTK.Input;


namespace TestJoystick
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer1.Interval = 10;
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            for (int i = 0; i < 4; i++)
            {
                var state = Joystick.GetState(i);
                if (state.IsConnected)
                {
                    float x = state.GetAxis(JoystickAxis.Axis1);
                    float y = state.GetAxis(JoystickAxis.Axis4);
                    label1.Text = "" + (int)(x * 101);
                    trackBar1.Value = (int)(x * 101);
                    label2.Text = "" + (int)(y * 101);
                    trackBar2.Value = (int)(y * 101);
                }
            }
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {

        }
    }
}
