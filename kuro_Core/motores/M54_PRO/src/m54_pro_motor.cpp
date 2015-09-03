#include "m54_pro_motor.h"

using namespace M54_PRO;

M54_PRO_Motor::M54_PRO_Motor(int id, MOTOR_TYPE type)
    :_ID_motor(id), _motor(type),_deviceIndex(0), _baud_speed(BAUD_1Mbps)
{
    DXL = new Dynamixel(PORT);
}

void M54_PRO_Motor::setBaudSpeed(BAUD_RATE br)
{
    _baud_speed = br;
    if(DXL->SetBaudrate(_baud_speed) == true)
    {
        printf( "Succeed to change the baudrate!\n" );
    }
    else
    {
        printf( "Failed to change the baudrate!\n" );
        printf( "Press any key to terminate...\n" );
    }
}

void M54_PRO_Motor::startMotor()
{
    int error = 0, result = COMM_RXFAIL;
    // Open device
    if( DXL->Connect() == 0 )
    {
        printf( "Failed to open USB2Dynamixel!\n" );
        printf( "Press any key to terminate...\n" );
        getchar();
    }
    else
        printf( "Succeed to open USB2Dynamixel!\n" );

    result = DXL->WriteByte(_ID_motor, TORQUE_ENABLED_RW, 1, &error);
    if(result == COMM_RXSUCCESS)
    {
        PrintErrorCode(error);
    }
    else
        PrintCommStatus(result);
}

void M54_PRO_Motor::moveMotor(double goal)
{
    int error =0;
    //DXL.WriteDWord( DEFAULT_ID, P_GOAL_POSITION_LL, GoalPos[index], &error);
    goal= (goal > 1023) ? 1023 : goal;
    goal= (goal < -1023) ? -1023 : goal;
    switch (_motor) {
    case JOINT:
        //{-125700, 125700}
        DXL->WriteDWord( _ID_motor, GOAL_POSITION_RW, goal, &error);
        break;
    case WHEEL:
        //{-8000, 8000}
        DXL->WriteDWord( _ID_motor, GOAL_VELOCITY_RW, goal, &error);
        break;
    default:
        break;
    }
}

void M54_PRO_Motor::stopMotor()
{
    DXL->Disconnect();
    printf("Terminar motor\r\n");

}

double M54_PRO_Motor::getPosition()
{

}

void M54_PRO_Motor::setType(MOTOR_TYPE type)
{
    int error = 0;
    _motor=type;
    switch (_motor) {
    case JOINT:
        //set angle mode
        DXL->WriteByte(_ID_motor, OPERATING_MODE_RW, POSITION_CONTROL_MODE, &error);
        break;
    case WHEEL:
        //set wheel mode
        DXL->WriteByte( _ID_motor, OPERATING_MODE_RW, VELOCITY_CONTROL_MODE, &error);
        break;
    default:
        break;
    }
}

MOTOR_TYPE M54_PRO_Motor::getType()
{
    return _motor;
}

void M54_PRO_Motor::setID(int id)
{
     _ID_motor = id;
}

int M54_PRO_Motor::getID()
{
    return _ID_motor;
}


// Print communication result
void PrintCommStatus(int CommStatus)
{
    switch(CommStatus)
    {
    case COMM_TXFAIL:
        printf("COMM_TXFAIL: Failed transmit instruction packet!\n");
        break;

    case COMM_TXERROR:
        printf("COMM_TXERROR: Incorrect instruction packet!\n");
        break;

    case COMM_RXFAIL:
        printf("COMM_RXFAIL: Failed get status packet from device!\n");
        break;

    case COMM_RXWAITING:
        printf("COMM_RXWAITING: Now recieving status packet!\n");
        break;

    case COMM_RXTIMEOUT:
        printf("COMM_RXTIMEOUT: There is no status packet!\n");
        break;

    case COMM_RXCORRUPT:
        printf("COMM_RXCORRUPT: Incorrect status packet!\n");
        break;

    default:
        printf("This is unknown error code!\n");
        break;
    }
}

// Print error bit of status packet
void PrintErrorCode(int ErrorCode)
{
    if(ErrorCode & ERRBIT_VOLTAGE)
        printf("Input voltage error!\n");

    if(ErrorCode & ERRBIT_ANGLE)
        printf("Angle limit error!\n");

    if(ErrorCode & ERRBIT_OVERHEAT)
        printf("Overheat error!\n");

    if(ErrorCode & ERRBIT_RANGE)
        printf("Out of range error!\n");

    if(ErrorCode & ERRBIT_CHECKSUM)
        printf("Checksum error!\n");

    if(ErrorCode & ERRBIT_OVERLOAD)
        printf("Overload error!\n");

    if(ErrorCode & ERRBIT_INSTRUCTION)
        printf("Instruction code error!\n");
}

