﻿using System;
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
                readFoto();
                if (MineroEvent != null)
                    MineroEvent(this, ev);
            }
        }

        public void readFoto()
        {
            try
            {
                List<byte> datos = new List<byte>();
                byte[] dat = new byte[1];
                if (clientSock.Connected)
                {
                    clientSock.Receive(dat);
                    ev.cmd = dat[0];
                    if (dat[0] == 0x13)
                    {
                        var total = 0;
                        var size = 921600;
                        do
                        {
                            var read = clientSock.Receive(ev.data, total, size - total, SocketFlags.None);
                            if (read == 0)
                            {
                                //If it gets here and you received 0 bytes it means that the Socket has Disconnected gracefully (without throwing exception) so you will need to handle that here
                            }
                            total += read;
                            //If you have sent 1024 bytes and Receive only 512 then it wil continue to recieve in the correct index thus when total is equal to 1024 you will have recieved all the bytes
                        } while (total != size);
                        //while (clientSock.Available < 307200) ;
                        //clientSock.Receive(ev.data);
                        /*while (datos.Count < (640 * 480 * 3))
                        {
                            clientSock.Receive(dat);
                            datos.Add(dat[0]);
                        }
                        ev.data = datos.ToArray();*/
                    }

                }
            }
            catch (Exception ex)
            {
                
            }
        }
        public void setEP(String host, int port)
        {
            ipEnd = new IPEndPoint(IPAddress.Parse(host), port);
        }
        public void writeMessage(int cmd, List<byte> data)
        {
            try
            {
                if (clientSock.Connected)
                {
                    byte[] b = new byte[1];
                    b[0] = (byte)cmd;
                    clientSock.Send(b);
                    var d = data.ToArray();
                    clientSock.Send(d);
                }
            }
            catch (Exception EX)
            {
                clientSock.Close();
            }
        }
        public Message readMessage()
        {
            Message m = new Message(Comandos.CMD1);
            try
            {
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
            }
            catch (Exception ex)
            {
            }
            return m;
        }

        internal bool connect()
        {
            try
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
            catch (Exception ex)
            {
                return false;
            }
        }
    }
}
