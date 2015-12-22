using System;
using System.Collections.Generic;
using System.IO.Ports;
using System.Text;

namespace MineroLibrary
{
    public class MagicPie
    {
        #region Variables
        byte[] datos = new byte[3];
        private int _speed;

        public int speed
        {
            get { return _speed; }
            set { _speed = value; }
        }

        private bool _sentido;

        public bool Sentido
        {
            get { return _sentido; }
            set { _sentido = value; }
        }

        private bool _freno;

        public bool Freno
        {
            get { return _freno; }
            set { _freno = value; }
        }

        SerialPort _serialPort;

        #endregion

        public MagicPie()
        {
            _freno = false;
            _sentido = false;
            _speed = 0;
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
        /// Definir velocidad
        /// </summary>
        /// <param name="value">Velocidad entre 0-255</param>
        public void setSpeed(int value)
        {
            datos[0] = 0x40;
            datos[1] = 0x10;
            datos[2] = (byte)value;
            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }

        public void setSG(int value)
        {
            datos[0] = 0x40;
            datos[1] = 0x10;
            datos[2] = (byte)value;
            if (_serialPort.IsOpen)
            {
                _serialPort.Write(datos, 0, 3);
            }
        }
    }
}
