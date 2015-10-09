using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Motor3Control
{
    public class Mensaje
    {
        private byte _cmd;
        public byte CMD
        {
            get { return _cmd; }
            set { _cmd = value; }
        }

        private int _nDatos;
        public int nDatos
        {
            get { return _nDatos; }
            set { _nDatos = value; }
        }

        public byte[] Datos = new byte[255];

        private byte _chk;
        public byte CheckSum
        {
            get { return _chk; }
            set { _chk = value; }
        }

        public static byte[] MensajeToArray(Mensaje m)
        {
            byte[] msg;
            int siz = 3 + m.nDatos;
            msg = new byte[siz];
            msg[0] = m._cmd;
            msg[1] = (byte)m._nDatos;
            for (int i = 0; i < m._nDatos; i++)
                msg[2 + i] = m.Datos[i];

            msg[siz - 1] = m._chk;
            return msg;
        }

        public static Mensaje ArrayToMensaje(byte[] msg)
        {
            Mensaje m = new Mensaje();

            m.CMD = msg[0];
            m.nDatos = msg[1];
            m.CheckSum = msg[0];
            m.CheckSum += msg[1];
            int siz = 3 + m.nDatos;
            for (int i = 0; i < m.nDatos; i++)
            {
                m.Datos[i] = msg[2 + i];
                m.CheckSum += msg[2 + i];
            }
            m.CheckSum =(byte)( m.CheckSum ^ m.CMD);
            return m;
        }
    }
}
