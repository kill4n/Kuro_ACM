#include "ax_12_motor.h"

using namespace AX_12;

AX_12_Motor::AX_12_Motor(int id, MOTOR_TYPE type)
    :_ID_motor(id), _motor(type),_deviceIndex(0), _baud_speed(BAUD_1Mbps)
{
}

void AX_12_Motor::setBaudSpeed(BAUD_RATE br)
{
    _baud_speed = br;
}

void AX_12_Motor::startMotor()
{
    printf( "\n\nStart Motor AX_12\n\n" );
    ///////// Open USB2Dynamixel ////////////
    if( dxl_initialize(_deviceIndex, _baud_speed) == 0 )
    {
        printf( "Failed to open USB2Dynamixel!\n" );
        printf( "Press Enter key to terminate...\n" );
        getchar();
    }
    else
        printf( "Succeed to open USB2Dynamixel!\n" );
}
void AX_12_Motor::moveMotor(double goal)
{
    goal= (goal > 1023) ? 1023 : goal;
    goal= (goal < -1023) ? -1023 : goal;
    switch (_motor) {
    case JOINT:
        dxl_write_word( _ID_motor, GOAL_POSITION_L_RW, goal );
        break;
    case WHEEL:
        if (goal>=0) {
            dxl_write_word( _ID_motor, MOVING_SPEED_L_RW, goal );
            dxl_write_word( _ID_motor, MOVING_SPEED_H_RW, 0 );
        } else {
            dxl_write_word( _ID_motor, MOVING_SPEED_L_RW, (goal * -1) );
            dxl_write_word( _ID_motor, MOVING_SPEED_H_RW, 1 );
        }
        break;
    default:
        break;
    }
}

void AX_12_Motor::stopMotor()
{
    dxl_terminate();
    printf("Terminar motor\r\n");
}

double AX_12_Motor::getPosition()
{

}

void AX_12_Motor::setType(MOTOR_TYPE type)
{
    _motor=type;
    switch (_motor) {
    case JOINT:
        //set angle mode
        dxl_write_word( _ID_motor, CW_ANGLE_LIMIT_L_RW, 512 );
        dxl_write_word( _ID_motor, CW_ANGLE_LIMIT_H_RW, 0 );
        dxl_write_word( _ID_motor, CCW_ANGLE_LIMIT_H_RW, 512 );
        dxl_write_word( _ID_motor, CCW_ANGLE_LIMIT_H_RW, 0 );
        break;
    case WHEEL:
        //set wheel mode
        dxl_write_word( _ID_motor, CW_ANGLE_LIMIT_L_RW, 0 );
        dxl_write_word( _ID_motor, CW_ANGLE_LIMIT_H_RW, 0 );
        dxl_write_word( _ID_motor, CCW_ANGLE_LIMIT_L_RW, 0 );
        dxl_write_word( _ID_motor, CCW_ANGLE_LIMIT_H_RW, 0 );
        break;
    default:
        break;
    }
}
MOTOR_TYPE AX_12_Motor::getType()
{
    return _motor;
}

void AX_12_Motor::setID(int id)
{
    _ID_motor = id;
}
int AX_12_Motor::getID()
{
    return _ID_motor;
}

//Funciones Auxiliares
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
void PrintErrorCode()
{
    if(dxl_get_rxpacket_error(ERRBIT_VOLTAGE) == 1)
        printf("Input voltage error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_ANGLE) == 1)
        printf("Angle limit error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_OVERHEAT) == 1)
        printf("Overheat error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_RANGE) == 1)
        printf("Out of range error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_CHECKSUM) == 1)
        printf("Checksum error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_OVERLOAD) == 1)
        printf("Overload error!\n");

    if(dxl_get_rxpacket_error(ERRBIT_INSTRUCTION) == 1)
        printf("Instruction code error!\n");
}
