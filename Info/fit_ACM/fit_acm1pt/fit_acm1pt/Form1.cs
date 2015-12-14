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

using MineroLibrary;
using AX_12;

using AForge;
using AForge.Video;
using AForge.Video.DirectShow;

using OpenTK.Input;

namespace fit_acm1pt
{
    public partial class Form1 : Form
    {
        int devIndeex = 0;

        IModeloInterface dm = new OmniModel();
        /*AX_12_Motor ax12_Rot;
        AX_12_Motor ax12_Dir;*/
        FilterInfoCollection videoDevices;
        VideoCaptureDevice videoSource;
        public Form1()
        {
            InitializeComponent();
            
            dm.setDeviceIndex(3);
            comboBox2.DataSource = Enum.GetValues(typeof(MODELO_TYPE));

            // enumerate video devices
            videoDevices = new FilterInfoCollection(
                     FilterCategory.VideoInputDevice);
            // create video source
            videoSource = new VideoCaptureDevice(
                    videoDevices[0].MonikerString);
            // set NewFrame event handler
            videoSource.NewFrame += new NewFrameEventHandler(video_NewFrame);

            /*ax12_Rot = new AX_12_Motor();
            ax12_Dir = new AX_12_Motor();

            ax12_Dir.setDeviceID(3);
            ax12_Rot.setDeviceID(3);
            ax12_Dir.setBaudSpeed(BAUD_RATE.BAUD_1Mbps);
            ax12_Rot.setBaudSpeed(BAUD_RATE.BAUD_1Mbps);*/
            //button3_Click(null, null);
        }

       
        private void button1_Click(object sender, EventArgs e)
        {
            //1 rueda
            String s = comboBox1.SelectedItem.ToString();
            string d = s.Remove(0, 3);
            devIndeex = int.Parse(d);
            dm.setDeviceIndex(devIndeex);
            if (!((OmniModel)dm).isConected)
            {
                dm.startModel();
                button1.Text = "Desconectar";
                videoSource.Start();
                timer1.Start();
            }
            else
            {
                videoSource.Stop();
                dm.stopModel();
                button1.Text = "Conectar";
                timer1.Stop();
            }
            //2 joint
            /*if (!ax12_Rot.isConected & !ax12_Dir.isConected)
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
            }*/

        }

        private void button2_Click(object sender, EventArgs e)
        {
            dm.setSpeed(int.Parse(textBox1.Text));
            dm.setDirection(int.Parse(textBox2.Text));
            /* ax12_Rot.moveMotor(int.Parse(textBox1.Text));
             ax12_Dir.moveMotor(int.Parse(textBox2.Text));*/
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

        private void button4_Click(object sender, EventArgs e)
        {
            var mod = ((MODELO_TYPE)comboBox2.SelectedItem);
            if (dm.isStarted())
            {
                dm.stopModel();
            }
            switch (mod)
            {
                case MODELO_TYPE.OMNIDIRECCIONAL:
                    dm = new OmniModel();
                    break;
                case MODELO_TYPE.DIFERENCIAL:
                    dm = new DifferModel();
                    break;
                case MODELO_TYPE.ACKERMKAN:
                    dm = new AckerModel();
                    break;
                default:
                    break;
            }
            dm.setDeviceIndex(devIndeex);
            dm.startModel();
            button1.Text = "Desconectar";
        }

        private void video_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            // get new frame

            pictureBox1.Image = (Bitmap)eventArgs.Frame.Clone();
            // process the frame
        }
        float x, y;
        private void timer1_Tick(object sender, EventArgs e)
        {
            for (int i = 0; i < 4; i++)
            {
                var state = Joystick.GetState(i);
                if (state.IsConnected)
                {
                    x = (int)(state.GetAxis(JoystickAxis.Axis1) * 101);
                    y = (int)(state.GetAxis(JoystickAxis.Axis4) * 101);
                }
            }
            var mod = ((MODELO_TYPE)comboBox2.SelectedItem);
            switch (mod)
            {
                case MODELO_TYPE.OMNIDIRECCIONAL:
                    dm.setSpeed((int)(x * 1023 / 100));
                    dm.setDirection((int)(y * 1023 / 100));
                    break;
                case MODELO_TYPE.DIFERENCIAL:
                    if (x != 0)
                    {
                        dm.setSpeed((int)(x * 1023 / 100));
                    }
                    else
                    {
                        dm.setDirection((int)(y * 1023 / 100));
                    }
                    break;
                case MODELO_TYPE.ACKERMKAN:
                    dm.setSpeed((int)(x * 1023 / 100));
                    dm.setDirection((int)(y * 1023 / 100));
                    break;
                default:
                    break;
            }
        }
    }
}
