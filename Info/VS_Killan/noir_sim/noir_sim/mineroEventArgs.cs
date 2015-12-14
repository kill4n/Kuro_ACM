using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace noir_sim
{
    class mineroEventArgs : EventArgs
    {
        public mineroEventArgs()
        {
            data = new byte[921600];
        }
        public Message m;
        public byte[]data;
        public int cmd;
    }
}
