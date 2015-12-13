using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using System.ComponentModel;

using System.Net;
using System.Net.Sockets;

namespace MineroLibrary
{
    public enum CMD_MINERO
    {
        CMD_MODE = 0x10,//cambio modo
        CMD_FOTO = 0x20 //pedir foto
    }

    public class minero_class
    {
        private int _puerto;

        public int puerto_con
        {
            get { return _puerto; }
            set { _puerto = value; }
        }

        IPEndPoint ipEnd;
        BackgroundWorker bw;
        Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        Socket clientSock;

        public minero_class(int puerto = 2134)
        {
            _puerto = puerto;
            ipEnd = new IPEndPoint(IPAddress.Any, _puerto);
            bw.DoWork += new DoWorkEventHandler(bw_DoWork);
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            clientSock = sock.Accept();
            //leer del cliente
            while (clientSock.Connected)
            {
                byte[] cmd = new byte[1];
                clientSock.Receive(cmd);
                byte[] data;
                switch (((CMD_MINERO)cmd[0]))
                {
                    case CMD_MINERO.CMD_MODE:
                        data = new byte[1];
                        clientSock.Receive(data);

                        break;
                    case CMD_MINERO.CMD_FOTO:

                        break;
                    default:
                        break;
                }

            }
        }

        public void conectar()
        {
            sock.Bind(ipEnd);
            sock.Listen(10);
            bw.RunWorkerAsync();
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
