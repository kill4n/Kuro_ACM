using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

using AX_12;

namespace fit_acm1pt
{
    public partial class Form1 : Form
    {
        AX_12_Motor ax12_Rot;
        AX_12_Motor ax12_Dir;

        public Form1()
        {
            InitializeComponent();
            ax12_Rot = new AX_12_Motor();
            ax12_Dir = new AX_12_Motor();

            ax12_Dir.setDeviceID(3);
            ax12_Rot.setDeviceID(3);
            ax12_Dir.setBaudSpeed(BAUD_RATE.BAUD_1Mbps);
            ax12_Rot.setBaudSpeed(BAUD_RATE.BAUD_1Mbps);
            button3_Click(null, null);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //1 rueda
            String s = comboBox1.SelectedItem.ToString();
            string d = s.Remove(0, 3);
            //2 joint
            if (!ax12_Rot.isConected & !ax12_Dir.isConected)
            {
                ax12_Dir.setDeviceID(int.Parse(d));
                ax12_Rot.setDeviceID(int.Parse(d));
                ax12_Rot.setID(1);
                ax12_Rot.startMotor();
                ax12_Rot.setType(MOTOR_TYPE.WHEEL);

                ax12_Dir.setID(2);
                ax12_Dir.startMotor();
                ax12_Dir.setType(MOTOR_TYPE.JOINT);
                ((Button)sender).Text = "Desconectar";
            }
            else
            {
                ax12_Dir.stopMotor();
                ax12_Rot.stopMotor();
                ((Button)sender).Text = "Conectar";
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            ax12_Rot.moveMotor(int.Parse(textBox1.Text));
            ax12_Dir.moveMotor(int.Parse(textBox2.Text));
        }

        private void button3_Click(object sender, EventArgs e)
        {
            var s = SerialPort.GetPortNames();
            comboBox1.Items.Clear();
            foreach (var item in s)
            {
                comboBox1.Items.Add(item);
            }
            if (comboBox1.Items.Count > 0)
                comboBox1.SelectedIndex = 0;
        }
    }
}
