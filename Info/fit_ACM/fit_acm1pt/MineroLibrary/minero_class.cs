using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.ComponentModel;

using System.Net;
using System.Net.Sockets;

using AForge;
using AForge.Video;
using AForge.Video.DirectShow;
using System.Drawing;
using System.IO;

namespace MineroLibrary
{
    public enum CMD_MINERO
    {
        CMD_MODE = 0x10,//cambio modo
        CMD_FOTO = 0x11, //pedir foto
        CMD_SND_FOTO = 0x13,
        CMD_DEF = 0xFF
    }

    public class minero_class
    {
        private int _puerto;

        public int puerto_con
        {
            get { return _puerto; }
            set { _puerto = value; }
        }

        MODELO_TYPE mod = MODELO_TYPE.OMNIDIRECCIONAL;

        IPEndPoint ipEnd;
        BackgroundWorker bw;
        JoyHelper joystick = new JoyHelper();
        Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        Socket clientSock;

        IModeloInterface modeloRobot = new OmniModel();

        FilterInfoCollection videoDevices;
        VideoCaptureDevice videoSource;

        JoyHelper joy = new JoyHelper();

        public event MineroHandler MineroEvent;
        public delegate void MineroHandler(object sender, MineroEventArgs e);

        Bitmap bmp1, bmp;

        public minero_class(int puerto = 2134)
        {

            bmp1 = new Bitmap(640, 480, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
            bw = new BackgroundWorker();
            _puerto = puerto;
            ipEnd = new IPEndPoint(IPAddress.Any, _puerto);
            bw.DoWork += new DoWorkEventHandler(bw_DoWork);

            modeloRobot.setDeviceIndex(3);

            try
            {
                // enumerate video devices
                videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
                // create video source
                videoSource = new VideoCaptureDevice(videoDevices[0].MonikerString);
                // set NewFrame event handler
                videoSource.NewFrame += videoSource_NewFrame;
            }
            catch (Exception ex)
            {

            }
            //jo¿ystick
            joy.JoystickEvent += joy_JoystickEvent;
        }

        void videoSource_NewFrame(object sender, NewFrameEventArgs eventArgs)
        {
            bmp1 = (Bitmap)eventArgs.Frame.Clone();
        }

        void joy_JoystickEvent(object sender, JoystickEventArgs e)
        {
            //recibi datos
            if (modeloRobot.isStarted())
            {
                switch (mod)
                {
                    case MODELO_TYPE.OMNIDIRECCIONAL:
                        modeloRobot.setSpeed((int)(e.axisVertical * 1023) - 3);
                        modeloRobot.setDirection((int)(e.axisHorizontal * 1023) - 3);
                        break;
                    case MODELO_TYPE.DIFERENCIAL:
                        if (((int)(e.axisVertical * 1023) - 3) != 0)
                        {
                            modeloRobot.setSpeed((int)(e.axisVertical * 1023) - 3);
                        }
                        else
                        {
                            modeloRobot.setDirection((int)(e.axisHorizontal * 1023) - 3);
                        }
                        break;
                    case MODELO_TYPE.ACKERMKAN:
                        modeloRobot.setSpeed((int)(e.axisVertical * 1023) - 3);
                        modeloRobot.setDirection((int)(e.axisHorizontal * 1023) - 3);
                        break;
                    default:
                        break;
                } 
            }
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            clientSock = sock.Accept();
            //leer del cliente
            try
            {
                while (clientSock.Connected)
                {
                    byte[] cmd = new byte[1];
                    clientSock.Receive(cmd);
                    byte[] data;
                    MineroEventArgs mEA;
                    MemoryStream ms = new MemoryStream();
                    switch (((CMD_MINERO)cmd[0]))
                    {
                        case CMD_MINERO.CMD_MODE:
                            data = new byte[1];
                            clientSock.Receive(data);
                            mod = (MODELO_TYPE)data[0];
                            if (modeloRobot.isStarted())
                            {
                                modeloRobot.stopModel();
                            }
                            switch (mod)
                            {
                                case MODELO_TYPE.OMNIDIRECCIONAL:
                                    modeloRobot = new OmniModel();
                                    break;
                                case MODELO_TYPE.DIFERENCIAL:
                                    modeloRobot = new DifferModel();
                                    break;
                                case MODELO_TYPE.ACKERMKAN:
                                    modeloRobot = new AckerModel();
                                    break;
                                default:
                                    break;
                            }
                            modeloRobot.setDeviceIndex(3);
                            modeloRobot.startModel();
                            mEA = new MineroEventArgs(CMD_MINERO.CMD_MODE, data, 1);
                            break;
                        case CMD_MINERO.CMD_FOTO:
                            data = new byte[1];
                            clientSock.Receive(data);

                            bmp = (Bitmap)bmp1.Clone();
                            // Save to memory using the Jpeg format
                            bmp.Save(ms, System.Drawing.Imaging.ImageFormat.Bmp);
                            // read to end
                            ms.SetLength(921600);
                            //ms.Position = 0;
                            byte[] bmpBytes = ms.ToArray();
                            bmp.Dispose();
                            ms.Close();
                            mEA = new MineroEventArgs(CMD_MINERO.CMD_FOTO, bmpBytes, bmpBytes.Length);
                            break;
                        default:
                            mEA = new MineroEventArgs(CMD_MINERO.CMD_DEF, cmd, 1);
                            break;
                    }
                    if (MineroEvent != null)
                        MineroEvent(this, mEA);
                }
            }
            catch (Exception ex)
            {
                var mes = ex.Message;
            }
        }

        public void conectar()
        {
            sock.Bind(ipEnd);
            sock.Listen(10);
            bw.RunWorkerAsync();

            if (!modeloRobot.isStarted())
            {
                modeloRobot.startModel();
                videoSource.Start();
                joy.conectar();
            }
            else
            {
                videoSource.Stop();
                modeloRobot.stopModel();
                joy.desconectar();
            }
        }

        public void sendData(CMD_MINERO comando, byte[] data)
        {
            if (clientSock.Connected)
            {
                byte[] cmd = new byte[1];
                cmd[0] = (byte)comando;
                clientSock.Send(cmd);
                clientSock.Send(data);
            }
        }
        public void desconectar()
        {
            if (clientSock.Connected)
            {
                clientSock.Close();
            }
        }


    }
}
