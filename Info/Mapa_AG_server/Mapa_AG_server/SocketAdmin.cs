using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Net;
using System.Net.Sockets;
using System.ComponentModel;

namespace Mapa_AG_server
{
    public class SocketAdmin
    {
        IPEndPoint ipEnd;
        Socket sock = new Socket(AddressFamily.InterNetwork,
            SocketType.Stream, ProtocolType.Tcp);
        public Socket clientSock;
        BackgroundWorker bg = new BackgroundWorker();

        public event sockAdminEventHandler sockEvent;

        public delegate void sockAdminEventHandler(object sender, sockEventArgs e);

        // Invoke the Changed event; called whenever list changes
        protected virtual void OnsockAdmi(sockEventArgs e)
        {
            if (sockEvent != null)
                sockEvent(this, e);
        }

        public SocketAdmin(int puerto)
        {
            ipEnd = new IPEndPoint(IPAddress.Any, puerto);
            sock.Bind(ipEnd);
            sock.Listen(10);
            bg.DoWork += bg_DoWork;
        }

        void bg_DoWork(object sender, DoWorkEventArgs e)
        {
            clientSock = sock.Accept();
            while (clientSock.Connected)
            {
                byte[] buff = new byte[3];
                clientSock.Receive(buff);

                switch (buff[0])
                {
                    case 0xAA://Mapa
                        OnsockAdmi(new sockEventArgs(0xBB, buff[1], buff[2]));
                        break;
                    case 0xCC://combustible
                        OnsockAdmi(new sockEventArgs(0xDD, buff[1], buff[2]));
                        break;
                    case 0xEE://movimiento
                        byte[] dir = new byte[1];
                        clientSock.Receive(dir);
                        OnsockAdmi(new sockEventArgs(0xFF, buff[1], buff[2], dir[0]));
                        break;
                    default:
                        break;
                }

            }
        }

        public void StartListen()
        {
            if (!bg.IsBusy)
            {
                bg.RunWorkerAsync();
            }
        }
    }
    public class sockEventArgs : EventArgs
    {
        public byte cmd, us1, us2, dat;
        public sockEventArgs(byte comando, byte usuario1,
            byte usuario2, byte data = 0)
        {
            this.cmd = comando;
            this.us1 = usuario1;
            this.us2 = usuario2;
            this.dat = data;
        }
    }
}
