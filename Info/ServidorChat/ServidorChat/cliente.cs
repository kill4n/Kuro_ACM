using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Net.Sockets;
using System.ComponentModel;

namespace ServidorChat
{
    public enum Comandos
    {
        Nombre,
        MensajeN
    }
    public class cliente
    {
        public string nombre = "";
        public string msj = "";
        public byte codigo1 = 0x07;
        public byte codigo2 = 0x76;

        public event MensajeEventHandler MensajeEvento;
        public delegate void MensajeEventHandler(object sender, clientEventArgs e);

        // Invoke the Changed event; called whenever list changes
        protected virtual void OnMensajeLlego(clientEventArgs e)
        {
            if (MensajeEvento != null)
                MensajeEvento(this, e);
        }

        public Socket cliSock;

        BackgroundWorker bw = new BackgroundWorker();

        public cliente(Socket s)
        {
            cliSock = s;
            bw.DoWork += bw_DoWork;
            bw.RunWorkerAsync();
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {

            try
            {
                while (this.cliSock.Connected)
                {
                    byte[] bu = new byte[1];
                    cliSock.Receive(bu);
                    switch (bu[0])
                    {
                        case 0xff:
                            nombre = "";
                            bu = new byte[2];
                            cliSock.Receive(bu);
                            codigo1 = bu[0];
                            codigo2 = bu[1];
                            bu = new byte[1];
                            do
                            {
                                cliSock.Receive(bu);
                                nombre += "" + (char)bu[0];
                            } while (bu[0] != 0xCC);
                            OnMensajeLlego(new clientEventArgs(nombre, Comandos.Nombre));
                            break;
                        case 0xAA:
                            msj = "";
                            bu = new byte[1];
                            do
                            {
                                cliSock.Receive(bu);
                                msj += "" + (char)bu[0];
                            } while (bu[0] != 0xDD);
                            OnMensajeLlego(new clientEventArgs(msj, Comandos.MensajeN));
                            break;
                        default:
                            break;
                    }
                }
            }
            catch (Exception ex)
            {

            }
        }
    }

    public class clientEventArgs : EventArgs
    {
        public string mensaje = "";
        public Comandos comand;
        public clientEventArgs(string ms, Comandos cmd)
        {
            mensaje = ms;
            comand = cmd;
        }
    }
}
