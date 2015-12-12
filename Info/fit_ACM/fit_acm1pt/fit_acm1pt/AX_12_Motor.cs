using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using ROBOTIS; // for dynamixel sdk

namespace AX_12
{
    public enum CONTROL_TABLE
    {
        ID_RW = 3,
        BAUD_RATE_RW = 4,
        CW_ANGLE_LIMIT_L_RW = 6,
        CW_ANGLE_LIMIT_H_RW = 7,
        CCW_ANGLE_LIMIT_L_RW = 8,
        CCW_ANGLE_LIMIT_H_RW = 9,
        TORQUE_ENABLED_RW = 18,
        GOAL_POSITION_L_RW = 30,    //GOAL POSITION
        GOAL_POSITION_H_RW = 31,    //GOAL POSITION
        MOVING_SPEED_L_RW = 32,     //GOAL SPEED
        MOVING_SPEED_H_RW = 33,     //GOAL SPEED
        PRESENT_POSITION_L_R = 36,
        PRESENT_POSITION_H_R = 37,
        PRESENT_SPEED_L_R = 38,
        PRESENT_SPEED_H_R = 39
    }

    public enum BAUD_RATE
    {
        BAUD_1Mbps = 1,
        BAUD_500Kbps = 3,
        BAUD_400Kbps = 4,
        BAUD_250Kbps = 7,
        BAUD_200Kbps = 9,
        BAUD_115200 = 16,
        BAUD_57600 = 34,
        BAUD_19200 = 103,
        BAUD_9600 = 207
    }

    public enum MOTOR_TYPE
    {
        JOINT,
        WHEEL
    }

    public class AX_12_Motor
    {
        #region Variables
        //Variables
        int _ID_motor;
        MOTOR_TYPE _motor;
        int _deviceIndex;
        BAUD_RATE _baud_speed;
        private bool _isConected;

        public bool isConected
        {
            get { return _isConected; }
        }

        #endregion

        public AX_12_Motor(int id = 0, MOTOR_TYPE type = MOTOR_TYPE.WHEEL,
            int deviceID = 3, BAUD_RATE baud_speed = BAUD_RATE.BAUD_1Mbps)
        {
            _ID_motor = id;
            _motor = type;
            _deviceIndex = deviceID;
            _baud_speed = baud_speed;
        }

        public void startMotor()
        {
            // Open device
            if (dynamixel.dxl_initialize(_deviceIndex, (int)_baud_speed) == 0)
            {
                Console.WriteLine("Failed to open USB2Dynamixel!");
                Console.WriteLine("Press any key to terminate...");
                Console.ReadKey(true);
                return;
            }
            else
                Console.WriteLine("Succeed to open USB2Dynamixel!");
            _isConected = true;
        }

        public void moveMotor(double goal = 0)
        {
            goal = (goal > 1023) ? 1023 : goal;
            goal = (goal < -1023) ? -1023 : goal;
            switch (_motor)
            {
                case MOTOR_TYPE.JOINT:
                    //290 - 512 - 734
                    goal += 512;
                    goal = (goal > 734) ? 734 : goal;
                    goal = (goal < 290) ? 290 : goal;
                    dynamixel.dxl_write_word(_ID_motor, (int)CONTROL_TABLE.GOAL_POSITION_L_RW, (int)goal);
                    break;
                case MOTOR_TYPE.WHEEL:
                    if (goal >= 0)
                    {
                        dynamixel.dxl_write_word(_ID_motor, (int)CONTROL_TABLE.MOVING_SPEED_L_RW, (int)goal);
                        dynamixel.dxl_write_word(_ID_motor, (int)CONTROL_TABLE.MOVING_SPEED_H_RW, 0);
                    }
                    else
                    {
                        dynamixel.dxl_write_word(_ID_motor, (int)CONTROL_TABLE.MOVING_SPEED_L_RW, (int)(1023 + (-1 * goal)));
                        dynamixel.dxl_write_word(_ID_motor, (int)CONTROL_TABLE.MOVING_SPEED_H_RW, 4);
                    }
                    break;
                default:
                    break;
            }
        }

        public void stopMotor()
        {
            dynamixel.dxl_terminate();
            Console.WriteLine("Terminar motor\r\n");
            _isConected = false;
        }

        //set get ID de motor
        public void setID(int id = 0)
        {
            _ID_motor = id;
        }
        public int getID()
        {
            return _ID_motor;
        }
        //set get tipo de motor
        public void setType(MOTOR_TYPE type = MOTOR_TYPE.WHEEL)
        {
            _motor = type;
        }
        public MOTOR_TYPE getType()
        {
            return _motor;
        }
        public void setDeviceID(int dev_ID)
        {
            _deviceIndex = dev_ID;
        }
        public void setBaudSpeed(BAUD_RATE baur_rate)
        {
            _baud_speed = baur_rate;
        }
    }
}
