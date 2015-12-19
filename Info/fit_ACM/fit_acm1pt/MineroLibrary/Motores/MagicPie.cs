using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MineroLibrary
{
    public class MagicPie
    {
        #region Variables
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
        #endregion

        public MagicPie()
        {
            _freno = false;
            _sentido = false;
            _speed = 0;
        }



        public void setSpeed()
        {


        }
    }
}
