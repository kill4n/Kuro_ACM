using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO.Ports;

namespace MineroLibrary
{
    public class Motores_arduino
    {
        byte[] datos = new byte[3];
        private int _speedD;
        public int speedD
        {
            get { return _speedD; }
            set { _speedD = value; }
        }

        private int _speedI;
        public int speedI
        {
            get { return _speedI; }
            set { _speedI = value; }
        }

        private bool _SGD;
        public bool SentidoGiroDerecho
        {
            get { return _SGD; }
            set { _SGD = value; }
        }

        private bool _SGI;
        public bool SentidoGiroIzquierdo
        {
            get { return _SGI; }
            set { _SGI = value; }
        }

        private bool _FD;
        public bool FrenoDerecho
        {
            get { return _FD; }
            set { _FD = value; }
        }

        private bool _FI;
        public bool FrenoIzquierdo
        {
            get { return _FI; }
            set { _FI = value; }
        }

        SerialPort _serialPort;

        public Motores_arduino()
        {
            speedD = 0;
            speedI = 0;
            SentidoGiroDerecho = false;
            SentidoGiroIzquierdo = false;
            FrenoDerecho = false;
            FrenoIzquierdo = false;

            _serialPort = new SerialPort();

            _serialPort.PortName = "COM4";
            _serialPort.BaudRate = 9600;
            _serialPort.DataBits = 8;
            _serialPort.Parity = Parity.None;
            _serialPort.StopBits = StopBits.One;

            _serialPort.ReadTimeout = 500;
            _serialPort.WriteTimeout = 500;
        }

        public void conectar(String port = "COM4")
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.Close();
            }
            _serialPort.PortName = port;
            _serialPort.Open();
        }
        /// <summary>
        /// Definir velocidad Derecha
        /// </summary>
        /// <param name="value">Velocidad entre 0-255</param>
        public void setSpeedDer(byte value)
        {
            datos[0] = 0x40;
            datos[1] = 0x10;
            datos[2] = value;

            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }

        /// <summary>
        /// Definir velocidad Izquierda
        /// </summary>
        /// <param name="value">Velocidad entre 0-255</param>
        public void setSpeedIzq(byte value)
        {
            datos[0] = 0x40;
            datos[1] = 0x20;
            datos[2] = value;

            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }

        public void updateRuedaDerecha()
        {
            datos[0] = 0x50;
            if (FrenoDerecho)
                datos[1] = 0x10;
            else
                datos[1] = 0x20;

            if (SentidoGiroDerecho)
                datos[1] = 0x10;
            else
                datos[1] = 0x20;

            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }

        public void updateRuedaIzquierda()
        {
            datos[0] = 0x60;
            if (FrenoIzquierdo)
                datos[1] = 0x10;
            else
                datos[1] = 0x20;

            if (SentidoGiroIzquierdo)
                datos[1] = 0x10;
            else
                datos[1] = 0x20;

            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }

        internal void desconectar()
        {
            if (_serialPort.IsOpen)
            {
                _serialPort.Close();
            }
        }
    }
}


