using MineroLibrary;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;



namespace GUIV2
{
    public partial class Form1 : Form
    {
        minero_class mc = new minero_class(2134, GLOBAL_MODE.MINERO);

        public Form1()
        {
            InitializeComponent();
            mc.MineroEvent += mc_MineroEvent;
            mc.conectar();            
        }

        void mc_MineroEvent(object sender, MineroEventArgs e)
        {
            switch (e.comando)
            {
                case CMD_MINERO.CMD_MODE:

                    break;
                case CMD_MINERO.CMD_FOTO:
                    byte[] da = new byte[921600];

                    mc.sendData(CMD_MINERO.CMD_SND_FOTO, e.data);
                    break;
                case CMD_MINERO.CMD_SND_FOTO:

                    break;
                case CMD_MINERO.CMD_DEF:

                    break;
                default:
                    break;
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            mc.desconectar();
        }
    }
}
