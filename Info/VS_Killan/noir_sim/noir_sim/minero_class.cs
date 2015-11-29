using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace noir_sim
{
    class minero_class
    {
        IPEndPoint ipEnd;
        BackgroundWorker bw;
        Socket clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        public event MineroHandler MineroEvent;
        public mineroEventArgs ev = new mineroEventArgs();
        public delegate void MineroHandler(object sender, mineroEventArgs e);

        public minero_class(String host, int port)
        {
            ipEnd = new IPEndPoint(IPAddress.Parse(host), port);
            bw = new BackgroundWorker();
            bw.DoWork += bw_DoWork;
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            while (clientSock.Connected)
            {
                ev.m = readMessage();
                if (MineroEvent!=null)
                    MineroEvent(this, ev);
            }
        }

        public void setEP(String host, int port)
        {
            ipEnd = new IPEndPoint(IPAddress.Parse(host), port);
        }

        public Message readMessage()
        {
            Message m = new Message(Comandos.CMD1);
            List<byte> datos = new List<byte>();
            byte[] dat = new byte[1];
            if (clientSock.Connected)
            {
                clientSock.Receive(dat);
                datos.Add(dat[0]);
                m = new Message((Comandos)dat[0]);
                clientSock.Receive(dat);
                datos.Add(dat[0]);
                while (datos.Count < datos[1] + 2)
                {
                    clientSock.Receive(dat);
                    datos.Add(dat[0]);
                    m.addMessage(dat[0]);
                }
                clientSock.Receive(dat);
            }
            return m;
        }


        internal bool connect()
        {
            if (clientSock.Connected)
            {
                clientSock.Close();
                return false;
            }
            else
            {                
                clientSock.Connect(ipEnd);
                bw.RunWorkerAsync();
                return true;
            }
        }
    }
}
