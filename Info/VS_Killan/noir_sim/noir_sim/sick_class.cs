using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading;

namespace noir_sim
{
    public class sick_class
    {
        IPEndPoint ipEnd;
        Socket clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);

        public event SickHandler SickEvent;
        public SickEventArgs ev = new SickEventArgs();
        public delegate void SickHandler(object sender, SickEventArgs e);

        public sick_class(String host, int port)
        {
            ipEnd = new IPEndPoint(IPAddress.Parse(host), port);
        }

        public bool connect()
        {
            if (clientSock.Connected)
            {
                clientSock.Close();
                return false;
            }
            else
            {
                clientSock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
                clientSock.Connect(ipEnd);

                send_recv("sRI 0");
                send_recv("sEI 76 1");
                send_recv("sRI 152");
                send_recv("sEI 62 1");
                send_recv("sRI E7");
                send_recv("sEI 59 1");
                send_recv("sRI DD");
                send_recv("sEI 55 1");
                return true;
            }
        }

        void send_recv(String s)//, String r)
        {
            sendMesage(s);
            Thread.Sleep(20);
            ev.data = ListToString(readMessage());
            SickEvent(this, ev);
        }

        public void sendMesage(String txtMsg)
        {
            List<byte> msg = new List<byte>();
            msg.Add(0x02);

            var ms = System.Text.Encoding.ASCII.GetBytes(txtMsg);
            foreach (byte m in ms)
            {
                msg.Add(m);
            }
            msg.Add(0x03);
            clientSock.Send(msg.ToArray(), msg.Count, SocketFlags.None);
        }
        List<byte> datooos = new List<byte>();
        public List<byte> readMessage()
        {
            datooos.Clear();
            //Crear el Arreglo de bytes a recibir
            byte[] Data = new byte[1];
            //Verificar que el cliente este conectado
            if (clientSock.Connected)
            {
                //Preguntar cuantos datos hay para leer
                while ((clientSock.Available > 0) || (Data[0] != 0x03))
                {
                    //Leer del socket y almacenar en Data
                    clientSock.Receive(Data);
                    datooos.Add(Data[0]);
                }
            }
            datooos.Remove(0x02);
            datooos.Remove(0x03);
            return datooos;
        }

        public void readAsync()
        {
            ev.data = ListToString(readMessage());
            ev.init = false;

            var s = ev.data.Split(' ');
            String[] t = new List<String>(s).GetRange(26, 271).ToArray();
            ev.data = "";
            for (int i = 0; i < t.Length; i++)
            {
                ev.data += t[i] + " ";
                ev.dataRaw[i] = Int32.Parse(t[i], System.Globalization.NumberStyles.HexNumber);
                ev.dataX[i] = (ev.dataRaw[i] * Math.Cos(ev.angulo[i]));
                ev.dataY[i] = (ev.dataRaw[i] * Math.Sin(ev.angulo[i]));
            }
            SickEvent(this, ev);
        }

        String ListToString(List<byte> lista)
        {
            String s = "";
            foreach (var li in lista)
                s += (char)li;
            return s;
        }


        public void Close()
        {
            clientSock.Close();
        }
    }
}
