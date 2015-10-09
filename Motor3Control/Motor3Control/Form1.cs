using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Motor3Control
{
    public partial class Form1 : Form
    {
        Mensaje mens1 = new Mensaje();
        Mensaje mens2 = new Mensaje();
        Mensaje mens3 = new Mensaje();
        public void RefreshPorts()
        {
            comboBox1.Items.Clear();
            var st = SerialPort.GetPortNames();
            foreach (string s in st)
                comboBox1.Items.Add(s);
            if (comboBox1.Items.Count > 0)
                comboBox1.SelectedIndex = 0;
        }
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            RefreshPorts();
            motor_ctrl1.SetId(1);
            motor_ctrl2.SetId(2);
            motor_ctrl3.SetId(3);

            motor_ctrl1.newValueMotor += motor_ctrl1_newValueMotor;
            motor_ctrl2.newValueMotor += motor_ctrl2_newValueMotor;
            motor_ctrl3.newValueMotor += motor_ctrl3_newValueMotor;
        }

        void motor_ctrl3_newValueMotor(object sender, MotorEventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                mens1.CMD = 0xA1;
                mens1.nDatos = 4;
                mens1.Datos[0] = (byte)e.motorData.id;
                mens1.Datos[1] = e.motorData.Sentido ? (byte)1 : (byte)0;
                mens1.Datos[2] = e.motorData.freno ? (byte)1 : (byte)0;
                mens1.Datos[3] = (byte)e.motorData.velocidad;
            }
        }

        void motor_ctrl2_newValueMotor(object sender, MotorEventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                mens2.CMD = 0xA1;
                mens2.nDatos = 4;
                mens2.Datos[0] = (byte)e.motorData.id;
                mens2.Datos[1] = e.motorData.Sentido ? (byte)1 : (byte)0;
                mens2.Datos[2] = e.motorData.freno ? (byte)1 : (byte)0;
                mens2.Datos[3] = (byte)e.motorData.velocidad;
            }
        }

        void motor_ctrl1_newValueMotor(object sender, MotorEventArgs e)
        {
            if (serialPort1.IsOpen)
            {
                mens3.CMD = 0xA1;
                mens3.nDatos = 4;
                mens3.Datos[0] = (byte)e.motorData.id;
                mens3.Datos[1] = e.motorData.Sentido ? (byte)1 : (byte)0;
                mens3.Datos[2] = e.motorData.freno ? (byte)1 : (byte)0;
                mens3.Datos[3] = (byte)e.motorData.velocidad;
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            RefreshPorts();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            switch (((Button)(sender)).Text)
            {
                case "Conectar":
                    if (serialPort1.IsOpen)
                        serialPort1.Close();

                    serialPort1.PortName = (String)comboBox1.SelectedItem;
                    serialPort1.Open();
                    ((Button)(sender)).Text = "Desconectar";
                    timer1.Start();
                    break;
                case "Desconectar":
                    if (serialPort1.IsOpen)
                        serialPort1.Close();
                    timer1.Stop();
                    ((Button)(sender)).Text = "Conectar";
                    break;
                default:
                    break;
            }

        }

        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            Mensaje m1 = new Mensaje();
            while (serialPort1.BytesToRead == 0) ;
            m1.CMD = (byte)serialPort1.ReadByte();
            while (serialPort1.BytesToRead == 0) ;
            m1.nDatos = (byte)serialPort1.ReadByte();
            for (int i = 0; i < m1.nDatos; i++)
            {
                while (serialPort1.BytesToRead == 0) ;
                m1.Datos[i] = (byte)serialPort1.ReadByte();
            }
            while (serialPort1.BytesToRead == 0) ;
            m1.CheckSum = (byte)serialPort1.ReadByte();

            if (m1.CMD == 0xB1)
            {
                motor_ctrl1.UpdateVel(m1.Datos[0]);
                motor_ctrl2.UpdateVel(m1.Datos[1]);
                motor_ctrl3.UpdateVel(m1.Datos[2]);
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            byte[] da1 = Mensaje.MensajeToArray(mens1);
            serialPort1.Write(da1, 0, da1.Length);

            byte[] da2 = Mensaje.MensajeToArray(mens2);
            serialPort1.Write(da2, 0, da2.Length);

            byte[] da3 = Mensaje.MensajeToArray(mens3);
            serialPort1.Write(da3, 0, da3.Length);

        }
    }
}
