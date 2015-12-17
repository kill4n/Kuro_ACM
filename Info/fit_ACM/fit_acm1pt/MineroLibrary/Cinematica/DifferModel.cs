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

        List<MagicPie> mp_rot;

        private GLOBAL_MODE _modo;

        public GLOBAL_MODE ModoOper
        {
            get { return _modo; }
            set { _modo = value; }
        }

        #endregion

        public DifferModel(GLOBAL_MODE modo)
        {
            _modo = modo;
            if (ModoOper == GLOBAL_MODE.MINI_MINERO)
            {
                ax12_Dir = new List<AX_12_Motor>();
                ax12_Rot = new List<AX_12_Motor>(); 
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
            setSpeed(0);
            setDirection(0);
            _isConected = true;
        }

        public void setSpeed(int goalSpeed)
        {
            _speed = goalSpeed;
            for (int i = 0; i < numRuedas; ++i)
            {
                if ((i % 2) != 0)
                    ax12_Rot[i].moveMotor(-_speed);
                else
                    ax12_Rot[i].moveMotor(_speed);
            }
        }

        public int getSpeed()
        {
            return _speed;
        }

        public void setDirection(int goalDir)
        {
            _direction = goalDir;
            for (int i = 0; i < numRuedas; ++i)
            {
                ax12_Rot[i].moveMotor(_direction);
            }
        }

        public int getDirection()
        {
            return _direction;
        }

        public void stopModel()
        {
            for (int i = 0; i < numRuedas; ++i)
            {
                ax12_Rot[i].moveMotor(0);
                ax12_Dir[i].moveMotor(0);
                ax12_Rot[i].stopMotor();
                ax12_Dir[i].stopMotor();
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
