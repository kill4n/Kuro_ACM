using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using OpenTK.Graphics;
using OpenTK.Graphics.OpenGL;

using System.IO;
using System.Runtime.InteropServices;

namespace noir_sim
{
    public partial class Form1 : Form
    {
        sick_class sickTim351;
        minero_class minACM1PT;
        SickEventArgs sea;
        bool loaded = false;
        Bitmap frame;
        int contFrames = 0;
        public Form1()
        {
            InitializeComponent();

            CheckForIllegalCrossThreadCalls = false;
            sickTim351 = new sick_class(textBox1.Text, int.Parse(textBox2.Text));
            sickTim351.SickEvent += sickTim351_SickEvent;

            frame = new Bitmap(640, 480);
            //g = Graphics.FromImage(frame);
            pictureBox1.Image = frame;

            minACM1PT = new minero_class(textBox3.Text, int.Parse(textBox4.Text));
            minACM1PT.MineroEvent += minACM1PT_MineroEvent;

            loaded = true;
        }

        void minACM1PT_MineroEvent(object sender, mineroEventArgs e)
        {
            try
            {
                frame = new Bitmap(640, 480);
                if (e.cmd == 0x13)
                {
                    /*int cont = 0;
                    for (int i = 0; i < 480; i++)
                    {
                        for (int j = 0; j < 640; j++)
                        {
                            frame.SetPixel(j, i, Color.FromArgb(e.data[cont], e.data[cont + 1], e.data[cont + 2]));
                            cont += 3;
                        }
                    }*/
                    frame = ShowImage(e.data);
                }
                pictureBox1.Image = frame;
                pictureBox1.Refresh();
                contFrames++;
                this.Text = "frames recibidos" + contFrames;
            }
            catch (Exception ex)
            {
                var q = "asd";
            }

        }

        public Bitmap ShowImage(byte[] sender)
        {
            Bitmap bitmap = new Bitmap(640, 480, System.Drawing.Imaging.PixelFormat.Format24bppRgb);
            System.Drawing.Imaging.BitmapData bmData = bitmap.LockBits(new Rectangle(0, 0, bitmap.Width, bitmap.Height),
                                                System.Drawing.Imaging.ImageLockMode.ReadWrite, bitmap.PixelFormat);
            IntPtr pNative = bmData.Scan0;

            Marshal.Copy(sender, 0, pNative, (640 * 480 * 3));
            //    
            bitmap.UnlockBits(bmData);

            return bitmap;
        }

        #region sickEvento y timer
        void sickTim351_SickEvent(object sender, SickEventArgs e)
        {
            if (e.init)
            {
                //textBox3.AppendText(e.data);
                //textBox3.AppendText("\r\n");
            }
            else
            {
                //textBox3.Text = e.data;
                sea = e;
                /* listBox1.Items.Clear();
                 foreach (var item in e.dataRaw)
                 {
                     listBox1.Items.Add(item);
                 }*/
            }
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            sickTim351.readAsync();
            glControl1.Invalidate();
        }
        private void button1_Click(object sender, EventArgs e)
        {

            if (sickTim351.connect())
            {
                ((Button)sender).Text = "Desconectar";
                this.Text = "Conectado: OK";
                timer1.Start();
            }
            else
            {
                ((Button)sender).Text = "Conectar";
                timer1.Stop();
            }
        }
        #endregion

        #region Opengl
        private void glControl1_Resize(object sender, EventArgs e)
        {
            if (!loaded)
                return;
            SetupViewport();
        }

        private void glControl1_Paint(object sender, PaintEventArgs e)
        {
            if (!loaded) // Play nice
                return;

            GL.Clear(ClearBufferMask.ColorBufferBit | ClearBufferMask.DepthBufferBit);

            GL.LoadIdentity();                       // Reset The View
            GL.PointSize(10.0f);
            GL.Translate(0.0f, 0.0f, -15.0f);
            GL.Color3(0.0, 0.0, 1.0);
            GL.Translate(0.0f, 0.0f, 0.0f);
            GL.Begin(PrimitiveType.Points);
            GL.Vertex3(0.0f, 0.0f, 0.0f);
            GL.End();
            GL.PointSize(2.0f);
            GL.Color3(1.0, 1.0, 1.0);

            if (sea != null)
            {
                GL.Begin(PrimitiveType.Points);
                for (int i = 0; i < 271; i++)
                {
                    GL.Vertex3(sea.dataX[i],
                               sea.dataY[i], 0.0);
                }
                GL.End();
            }
            GL.Flush();
            glControl1.SwapBuffers();
        }

        private void glControl1_Load(object sender, EventArgs e)
        {
            loaded = true;
            GL.ClearColor(Color.Black);
            SetupViewport();
        }

        private void SetupViewport()
        {
            GL.Viewport(0, 0, glControl1.Width, glControl1.Height);
            GL.MatrixMode(MatrixMode.Projection);
            GL.LoadIdentity();
            double wld = 10000.0;
            GL.Ortho(-wld, wld, -wld, wld, 5.0, 15.0);
            GL.MatrixMode(MatrixMode.Modelview);
        }
        #endregion
        #region conexion minero

        #endregion
        private void button2_Click(object sender, EventArgs e)
        {
            minACM1PT.setEP(textBox3.Text, int.Parse(textBox4.Text));
            if (minACM1PT.connect())
            {
                ((Button)sender).Text = "Desconectar";
                this.Text = "Conectado: OK";
                btn_modelo.Enabled = true;
                timer2.Start();
            }
            else
            {
                ((Button)sender).Text = "Conectar";
                btn_modelo.Enabled = false;
                timer2.Stop();
            }
        }

        private void btn_modelo_Click(object sender, EventArgs e)
        {
            List<byte> data = new List<byte>();
            if (rb_omn.Checked)
            {
                data.Add(0x21);
                minACM1PT.writeMessage(0x10, data);
            }
            if (rb_dif.Checked)
            {
                data.Add(0x22);
                minACM1PT.writeMessage(0x10, data);
            }
            if (rb_ack.Checked)
            {
                data.Add(0x23);
                minACM1PT.writeMessage(0x10, data);
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            List<byte> data = new List<byte>();
            data.Add(0x13);
            minACM1PT.writeMessage(0x11, data);

        }
    }
}
