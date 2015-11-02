using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace Mapa_AG_server
{
    public partial class Form1 : Form
    {
        string path = "";
        bool validData = false;
        Mapa m = new Mapa(12, 30);
        SocketAdmin sockA;
        public Form1()
        {
            InitializeComponent();
            pictureBox1.Image = m.MapaImg;
            pictureBox1.AllowDrop = true;
        }

        void sockA_sockEvent(object sender, sockEventArgs e)
        {
            try
            {
                if (sockA.clientSock.Connected)
                {
                    byte[] bu;
                    switch (e.cmd)
                    {
                        case 0xBB:
                            bu = new byte[m.lado * m.lado + 3];
                            bu[0] = e.cmd;
                            bu[1] = e.us2;
                            bu[bu.Length - 1] = e.us1;
                            var gm = m.getMapa();
                            for (int i = 0; i < bu.Length - 3; i++)
                            {
                                bu[i + 2] = gm[i];
                            }
                            sockA.clientSock.Send(bu);
                            break;
                        case 0xDD:
                            bu = new byte[4];
                            bu[0] = e.cmd;
                            bu[1] = e.us2;
                            bu[2] = 5;
                            bu[3] = e.us1;
                            sockA.clientSock.Send(bu);
                            break;
                        case 0xFF://movimiento
                            bu = new byte[m.lado * m.lado + 3];
                            bu[0] = e.cmd;
                            bu[1] = e.us2;
                            bu[2] = 0x33;
                            bu[3] = e.us1;
                            sockA.clientSock.Send(bu);
                            //mover carro e.data
                            m.moverCarro(((Direccion)e.dat));
                            break;
                        default:
                            break;
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog(this) == System.Windows.Forms.DialogResult.OK)
            {
                if ((openFileDialog1.FileName != "") &&
                    (File.Exists(openFileDialog1.FileName)))
                {
                    using (StreamReader sr = new StreamReader(openFileDialog1.FileName))
                    {
                        string lin = "";
                        int con = 0;
                        lin = sr.ReadLine();
                        m.lado = ((lin.Length + 1) / 2);
                        do
                        {
                            var s = lin.Split(';');
                            for (int i = 0; i < s.Length; i++)
                            {
                                m.PintarPunto(con, i, (TipoCelda)int.Parse(s[i]));
                            }
                            con++;
                        } while ((lin = sr.ReadLine()) != null);

                        pictureBox1.Image = m.MapaImg;
                    }
                }
            }
        }

        private void pictureBox1_DragDrop(object sender, DragEventArgs e)
        {
            if ((validData) && (path != ""))
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    string lin = "";
                    int con = 0;
                    lin = sr.ReadLine();
                    m.lado = ((lin.Length + 1) / 2);
                    do
                    {
                        var s = lin.Split(';');
                        for (int i = 0; i < s.Length; i++)
                        {
                            m.PintarPunto(i, con, (TipoCelda)int.Parse(s[i]));
                        }
                        con++;
                    } while ((lin = sr.ReadLine()) != null);
                    
                    pictureBox1.Image = m.MapaImg;
                }
                e.Effect = DragDropEffects.Copy;
            }
        }

        private void pictureBox1_DragEnter(object sender, DragEventArgs e)
        {
            string filename;
            validData = GetFilename(out filename, e);
            if (validData)
            {
                path = filename;
                e.Effect = DragDropEffects.Copy;
            }
            else
            {
                path = "";
                e.Effect = DragDropEffects.None;
            }
        }

        protected bool GetFilename(out string filename, DragEventArgs e)
        {
            bool ret = false;
            filename = String.Empty;

            if ((e.AllowedEffect & DragDropEffects.Copy) == DragDropEffects.Copy)
            {
                Array data = ((IDataObject)e.Data).GetData("FileName") as Array;
                if (data != null)
                {
                    if ((data.Length == 1) && (data.GetValue(0) is String))
                    {
                        filename = ((string[])data)[0];
                        string ext = Path.GetExtension(filename).ToLower();
                        if ((ext == ".map") || (ext == ".txt"))
                        {
                            ret = true;
                        }
                    }
                }
            }
            return ret;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            sockA = new SocketAdmin(int.Parse(textBox1.Text));
            sockA.sockEvent += sockA_sockEvent;
            sockA.StartListen();
        }

    }
}
