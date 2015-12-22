using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using AX_12;
using System.Diagnostics;

namespace MineroLibrary
{
    public class DifferModel : IModeloInterface
    {
        #region Variables
        const int numRuedas = 6;
        List<AX_12_Motor> ax12_Rot;
        List<AX_12_Motor> ax12_Dir;

        int _speed, _direction;
        private int _device_index;
        public int Device_Index
        {
            get { return _device_index; }
            set { _device_index = value; }
        }
        private bool _isConected;

        public bool isConected
        {
            get { return _isConected; }
        }

        Motores_arduino mot_rot;

        private GLOBAL_MODE _modo;

        public GLOBAL_MODE ModoOper
        {
            get { return _modo; }
            set { _modo = value; }
        }

        #endregion

        public DifferModel(GLOBAL_MODE modo = GLOBAL_MODE.MINERO)
        {
            _modo = modo;
            if (ModoOper == GLOBAL_MODE.MINI_MINERO)
            {
                ax12_Dir = new List<AX_12_Motor>();
                ax12_Rot = new List<AX_12_Motor>();
            }
            else
            {
                mot_rot = new Motores_arduino();
                mot_rot.SentidoGiroIzquierdo = true;
            }
            _isConected = false;
        }

        public void startModel()
        {
            Debug.WriteLine("iniciando Diferencial.");
            if (ModoOper == GLOBAL_MODE.MINI_MINERO)
            {
                Debug.WriteLine("mini_minero");
                for (int i = 0; i < numRuedas; ++i)
                {
                    ax12_Dir.Add(new AX_12_Motor());
                    ax12_Rot.Add(new AX_12_Motor());
                }
                for (int i = 0; i < numRuedas; ++i)
                {
                    ax12_Dir[i].setDeviceID(_device_index);
                    ax12_Rot[i].setDeviceID(_device_index);
                    ax12_Dir[i].setBaudSpeed(BAUD_RATE.BAUD_1Mbps);
                    ax12_Rot[i].setBaudSpeed(BAUD_RATE.BAUD_1Mbps);
                }

                for (int i = 0; i < numRuedas; ++i)
                {
                    ax12_Rot[i].setID(i + 7);
                    ax12_Rot[i].startMotor();
                    ax12_Rot[i].setType(MOTOR_TYPE.WHEEL);

                    ax12_Dir[i].setID(i + 1);
                    ax12_Dir[i].startMotor();
                    ax12_Dir[i].setType(MOTOR_TYPE.JOINT);
                }
            }
            else
            {
                Debug.WriteLine("minero");
                var str = "COM" + _device_index;
                mot_rot.conectar(str);
            }
            setSpeed(0);
            setDirection(0);
            _isConected = true;
        }

        public void setSpeed(int goalSpeed)
        {
            _speed = goalSpeed;
            if (ModoOper == GLOBAL_MODE.MINI_MINERO)
            {
                for (int i = 0; i < numRuedas; ++i)
                {
                    if ((i % 2) != 0)
                        ax12_Rot[i].moveMotor(-_speed);
                    else
                        ax12_Rot[i].moveMotor(_speed);
                }
            }
            else
            {
                if (Math.Sign(goalSpeed) == 1)
                {
                    mot_rot.SentidoGiroDerecho = false;
                    mot_rot.SentidoGiroDerecho = true;
                }
                if (Math.Sign(goalSpeed) == -1)
                {
                    mot_rot.SentidoGiroDerecho = true;
                    mot_rot.SentidoGiroDerecho = false;
                }

                mot_rot.updateRuedaDerecha();
                mot_rot.updateRuedaIzquierda();

                var vel = (byte)Math.Abs(goalSpeed);
                mot_rot.setSpeedDer(vel);
                mot_rot.setSpeedIzq(vel);
            }
        }

        public int getSpeed()
        {
            return _speed;
        }

        public void setDirection(int goalDir)
        {
            _direction = goalDir;
            if (ModoOper == GLOBAL_MODE.MINI_MINERO)
            {
                for (int i = 0; i < numRuedas; ++i)
                {
                    ax12_Rot[i].moveMotor(_direction);
                }
            }
            else
            {
                if (goalDir > 0)
                {
                    mot_rot.SentidoGiroDerecho = false;
                    mot_rot.SentidoGiroDerecho = false;

                    mot_rot.updateRuedaDerecha();
                    mot_rot.updateRuedaIzquierda();

                    var vel = (byte)(Math.Abs(_direction));

                    mot_rot.setSpeedDer(vel);
                    mot_rot.setSpeedIzq(vel);
                }
                else
                {
                    mot_rot.SentidoGiroDerecho = true;
                    mot_rot.SentidoGiroDerecho = true;

                    mot_rot.updateRuedaDerecha();
                    mot_rot.updateRuedaIzquierda();

                    var vel = (byte)(Math.Abs(_direction));

                    mot_rot.setSpeedDer(vel);
                    mot_rot.setSpeedIzq(vel);                    
                }
            }
        }

        public int getDirection()
        {
            return _direction;
        }

        public void stopModel()
        {
            if (_modo == GLOBAL_MODE.MINI_MINERO)
            {
                for (int i = 0; i < numRuedas; ++i)
                {
                    ax12_Rot[i].moveMotor(0);
                    ax12_Dir[i].moveMotor(0);
                    ax12_Rot[i].stopMotor();
                    ax12_Dir[i].stopMotor();
                }
            }
            else
            {
                mot_rot.setSpeedDer(0);
                mot_rot.setSpeedIzq(0);
                mot_rot.desconectar();
            }
            _isConected = false;
        }

        public void setDeviceIndex(int devInd)
        {
            _device_index = devInd;
        }

        public bool isStarted()
        {
            return _isConected;
        }

        public void setModoOperacion(GLOBAL_MODE modoOperacion)
        {
            _modo = modoOperacion;
        }
    }
}
