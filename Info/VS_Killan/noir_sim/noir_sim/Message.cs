using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace noir_sim
{
    public enum Comandos
    {
        CMD1 = 0xC1,
        CMD_FRAME_CAM = 0xC2,
        CMD_MODE_CARR = 0xC3
    }

    public class Message
    {
        public Comandos CMD;
        public int LongMsg
        {
            get { return Msg.Count; }
        }
        List<byte> Msg;
        public byte getCheckSum()
        {
            byte sum = 0;
            sum += (byte)this.CMD;
            sum += (byte)this.LongMsg;

            for (int i = 0; i < this.LongMsg; i++)
                sum += (byte)this.Msg[i];

            return (byte)((byte)sum ^ (byte)this.CMD);
        }

        public Message(Comandos comando)
        {
            CMD = comando;
            Msg = new List<byte>();
        }

        public int addMessage(byte bt)
        {
            Msg.Add(bt);
            return Msg.Count;
        }

        public static byte[] ToByteArray(Message msg)
        {
            byte[] dat = new byte[msg.LongMsg + 3];
            byte sum = 0;
            dat[0] = (byte)msg.CMD;
            dat[1] = (byte)msg.LongMsg;
            for (int i = 0; i < msg.LongMsg; i++)
                dat[2 + i] = msg.Msg[i];

            foreach (byte b in dat)
                sum += b;

            dat[msg.LongMsg + 2] = (byte)((byte)sum ^ (byte)dat[0]);

            return dat;
        }
        public static Message FromByteArray(byte[] ar)
        {
            Message msg = new Message((Comandos)ar[0]);
            msg.Msg.Clear();
            for (int i = 0; i < ar[1]; i++)
            {
                msg.addMessage(ar[2 + i]);
            }

            return msg;
        }
        public string toString()
        {
            string s = "";

            var q = Message.ToByteArray(this);

            foreach (byte b in q)
            {
                s += String.Format(" {0} ;", b);
            }
            s = s.Remove(s.Length - 2);

            return s;
        }

    }
}
