using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Motor3Control
{
    public partial class Motor_ctrl : UserControl
    {
        public motor mo = new motor();
        public delegate void StatusUpdateHandler(object sender, MotorEventArgs e);
        public event StatusUpdateHandler newValueMotor;

        public Motor_ctrl()
        {
            InitializeComponent();
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            UpdateStatus();
            textBox2.Text = "" + trackBar1.Value;
        }

        private void UpdateStatus()
        {
            // Make sure someone is listening to event
            if (newValueMotor == null) return;

            MotorEventArgs args = new MotorEventArgs(trackBar1.Value, cbSentido.Checked, cbFreno.Checked, Decimal.ToInt32(numericUpDown1.Value));
            newValueMotor(this, args);
        }

        private void cbSentido_CheckedChanged(object sender, EventArgs e)
        {
            UpdateStatus();
        }

        private void cbFreno_CheckedChanged(object sender, EventArgs e)
        {
            UpdateStatus();
        }

        public void UpdateVel(int vel)
        {
            textBox1.Text = "" + vel;
            progressBar1.Value = vel;
        }

        public void SetId(int id)
        {
            numericUpDown1.Value = id;
        }
    }
}
