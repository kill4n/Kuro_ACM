using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MineroLibrary
{
    public class MineroEventArgs : EventArgs
    {
        public CMD_MINERO comando;
        public byte[] data = new byte[921600];
        public int dataL;
        public MineroEventArgs(CMD_MINERO cmd, byte[] datos, int dataLenght)
        {
            comando = cmd;
            data = datos;
            dataL = dataLenght;
        }
    }
}
