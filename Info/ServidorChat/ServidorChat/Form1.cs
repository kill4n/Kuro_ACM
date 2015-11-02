using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ServidorChat
{
    public partial class Form1 : Form
    {
        public List<cliente> particip = new List<cliente>();
        IPEndPoint ipEnd = new IPEndPoint(IPAddress.Any, 5544);
        Socket sock = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        BackgroundWorker bw = new BackgroundWorker();

        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            sock.Bind(ipEnd);
            sock.Listen(20);

            bw.DoWork += bw_DoWork;
        }

        void bw_DoWork(object sender, DoWorkEventArgs e)
        {
            while (true)
            {
                particip.Add(new cliente(sock.Accept()));
                particip.LastOrDefault().MensajeEvento += Form1_MensajeEvento;
                button2.Enabled = true;
                this.Text = "clientes conectados: " + particip.Count;
            }
        }

        void Form1_MensajeEvento(object sender, clientEventArgs e)
        {
            switch (e.comand)
            {
                case Comandos.Nombre:
                    listBox1.Items.Add(((cliente)sender).nombre);
                    break;
                case Comandos.MensajeN:
                    string menf = ((cliente)sender).nombre + ": " + e.mensaje + "\r\n";
                    this.textBox1.AppendText(menf);

                    byte[] dat = new byte[menf.Length];
                    var ca = menf.ToCharArray();
                    for (int i = 0; i < menf.Length; i++)
                    {
                        dat[i] = (byte)ca[i];
                    }
                    foreach (cliente c in particip)
                    {
                        c.cliSock.Send(dat);
                    }
                    break;
                default:
                    break;
            }

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            bw.RunWorkerAsync();
            ((Button)sender).Enabled = false;
        }

        private void button2_Click(object sender, EventArgs e)
        {

            string menf = "Servidor: " + textBox2.Text + "\r\n";
            this.textBox1.AppendText(menf);

            byte[] dat = new byte[menf.Length];
            var ca = menf.ToCharArray();
            for (int i = 0; i < menf.Length; i++)
            {
                dat[i] = (byte)ca[i];
            }
            foreach (cliente c in particip)
            {
                c.cliSock.Send(dat);
            }
        }
    }
}
