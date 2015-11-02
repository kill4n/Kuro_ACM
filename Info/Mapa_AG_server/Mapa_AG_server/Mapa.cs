using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Mapa_AG_server
{
    public enum Direccion
    {
        Arriba = 0xD0,
        Abajo = 0xD1,
        Dercha = 0xD2,
        Izquie = 0xD3
    }
    public enum TipoCelda
    {
        Vacio,
        Pozo = 2,
        Carro = 5
    }
    public class Mapa
    {
        private int _xCar;

        public int xCar
        {
            get { return _xCar; }
            set
            {
                if (value < 0)
                {
                    _xCar = 0;
                }
                else
                {
                    if (value >= lado)
                    {
                        _xCar = lado - 1;
                    }
                    else
                    {
                        _xCar = value;
                    }
                }
            }
        }

        private int _yCar;

        public int yCar
        {
            get { return _yCar; }
            set {
                if (value < 0)
                {
                    _yCar = 0;
                }
                else
                {
                    if (value >= lado)
                    {
                        _yCar = lado - 1;
                    }
                    else
                    {
                        _yCar = value;
                    }
                } 
                
            }
        }


        private TipoCelda[,] myMapa;

        private int lc = 20;
        public int LadoCuadrado
        {
            get { return lc; }
            set
            {
                if (value < 10)
                {
                    lc = 10;
                }
                else
                {
                    lc = value;
                }
            }
        }

        private int _lado;
        public int lado
        {
            get { return _lado; }
            set
            {
                if (value < 0)
                {
                    _lado = 1;
                }
                else
                {
                    _lado = value;
                }
                _mapa = new Bitmap(_lado * lc, _lado * lc);
                g = Graphics.FromImage(_mapa);
                myMapa = new TipoCelda[_lado, _lado];
                iniciar();
            }
        }

        private Bitmap _mapa;
        public Bitmap MapaImg
        {
            get { return _mapa; }
            set { _mapa = value; }
        }
        Graphics g;

        public Mapa(int lados, int ancho)
        {
            LadoCuadrado = ancho;
            lado = lados;
        }

        private void iniciar()
        {
            LimpiarMapa();
            PintarGrilla();
        }

        private void LimpiarMapa()
        {
            g.Clear(Color.White);
        }

        private void PintarGrilla()
        {
            g.DrawRectangle(new Pen(Color.Black), 0, 0, (lc * _lado) - 1, (lc * _lado) - 1);
            for (int i = 0; i < _lado; i++)
            {
                g.DrawLine(new Pen(Color.Black), i * lc, 0, (i * lc), lc * _lado);
                g.DrawLine(new Pen(Color.Black), 0, i * lc, lc * _lado, (i * lc));
            }
        }

        public void PintarPunto(int x, int y, TipoCelda tc)
        {
            switch (tc)
            {
                case TipoCelda.Vacio:
                    g.FillRectangle(new SolidBrush(Color.White), x * lc + 1, y * lc + 1, lc - 1, lc - 1);
                    break;
                case TipoCelda.Pozo:
                    g.FillRectangle(new SolidBrush(Color.Green), x * lc + 1, y * lc + 1, lc - 1, lc - 1);
                    break;
                case TipoCelda.Carro:
                    g.FillRectangle(new SolidBrush(Color.Red), x * lc + 1, y * lc + 1, lc - 1, lc - 1);
                    _xCar = x;
                    _yCar = y;
                    break;
                default:
                    break;
            }
            myMapa[x, y] = tc;
            PintarGrilla();
        }

        public void moverCarro(Direccion d)
        {
            switch (d)
            {
                case Direccion.Arriba:
                    if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                    {
                        PintarPunto(_xCar, _yCar, TipoCelda.Vacio);
                        yCar--;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    else
                    {
                        yCar--;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }

                    break;
                case Direccion.Abajo:
                    if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                    {
                        PintarPunto(_xCar, _yCar, TipoCelda.Vacio);
                        yCar++;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    else
                    {
                        yCar++;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    break;
                case Direccion.Dercha:
                    if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                    {
                        PintarPunto(_xCar, _yCar, TipoCelda.Vacio);
                        xCar++;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    else
                    {
                        xCar++;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    break;
                case Direccion.Izquie:
                    if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                    {
                        PintarPunto(_xCar, _yCar, TipoCelda.Vacio);
                        xCar--;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    else
                    {
                        xCar--;
                        if (myMapa[_xCar, _yCar] != TipoCelda.Pozo)
                        {
                            PintarPunto(_xCar, _yCar, TipoCelda.Carro);
                        }
                    }
                    break;
                default:
                    break;
            }
        }

        public byte[] getMapa()
        {
            byte[] mapByte = new byte[_lado * _lado];
            for (int i = 0; i < _lado; i++)
            {
                for (int j = 0; j < _lado; j++)
                {
                    mapByte[i * lado + j] = (byte)myMapa[j, i];
                }
            }

            return mapByte;
        }
    }
}
