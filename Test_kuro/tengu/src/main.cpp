#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <getopt.h>
#include <string.h>
#include <termios.h>
#include "dynamixel.h"

using namespace std;
using namespace Thor;

Dynamixel DXL("/dev/ttyUSB0");
/*clase :)
                               (0 0)
                       ---oOO-- (_) ----oOO---
                     ╔═════════════════════════╗
                     ║  I Love you Bb     !..♥ ║
                     ╚═════════════════════════╝
                        -------------------
                              |__|__|
                               || ||
                              ooO Ooo



                            oooO
                          (....)     Oooo
                           ...(     (....)
                            ._)      )../
                                     (_/
                        Solo pasaba por aquí
                  ¡Saludos!


o       o
 \_____/
 /=O=O=\     _______
/   ^   \   /\\\\\\\\
\ \___/ /  /\   ___  \
 \_ V _/  /\   /\\\\  \
  \  \__/\   /\ @_/  /
   \____\____\______/


 *    By: Karin Muñoz*/
int _getch()
{
    struct termios oldt, newt;
    int ch;
    tcgetattr( STDIN_FILENO, &oldt );
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr( STDIN_FILENO, TCSANOW, &newt );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt );
    return ch;
}

int kbhit(void)
{
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if(ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

// Control table address
#define P_TORQUE_ENABLE         562
#define P_GOAL_POSITION_LL      596
#define P_GOAL_VELOCITY_LL      600
#define P_PRESENT_POSITION_LL   611
#define P_PRESENT_VELOCITY_LL   615
#define P_MOVING                610

// Defulat setting
#define DEFAULT_ID              7
#define DEFAULT_BAUDNUM         2 // 115,200

void PrintCommStatus(int CommStatus);
void PrintErrorCode(int ErrorCode);

int main()
{    
    int PresentPos = 0;
    int PresentVel = 0;
    int index = 0, result = COMM_TXFAIL, error = 0, Moving = 1;
    int GoalPos[2] = {-125700, 125700};
    int GoalVel[2] = {-8000, 8000};

    Dynamixel DXL("/dev/ttyUSB0");

    // Open device
    if( DXL.Connect() == 0 )
    {
        printf( "Failed to open USB2Dynamixel!\n" );
        printf( "Press any key to terminate...\n" );
        _getch();
        return 0;
    }
    else
        printf( "Succeed to open USB2Dynamixel!\n" );

    if(DXL.SetBaudrate(DEFAULT_BAUDNUM) == true)
    {
        printf( "Succeed to change the baudrate!\n" );
    }
    else
    {
        printf( "Failed to change the baudrate!\n" );
        printf( "Press any key to terminate...\n" );
        _getch();
        return 0;
    }

    result = DXL.WriteByte(DEFAULT_ID, P_TORQUE_ENABLE, 1, &error);

    if(result == COMM_RXSUCCESS)
    {
        PrintErrorCode(error);
    }
    else
        PrintCommStatus(result);

    while(1)
    {
        printf("Definir Velocidad (-8000,8000) \r\n");
        cin>>GoalVel[0];
        printf( "Presione Enter para continuar!(presione ESC y Enter para salir)\n" );
        if(_getch() == 0x1b)
            break;

        // Write goal position
        //DXL.WriteDWord( DEFAULT_ID, P_GOAL_POSITION_LL, GoalPos[index], &error);
        // Write goal Speed
        result = DXL.WriteDWord( DEFAULT_ID, P_GOAL_VELOCITY_LL, GoalVel[index], &error);
        if(result == COMM_RXSUCCESS)
        {
            PrintErrorCode(error);
        }
        else
            PrintCommStatus(result);
        // Change goal position
        /* for(int i=0;i<1;i++)
        {
            // Read present position
            //result = DXL.ReadDWord(DEFAULT_ID, P_PRESENT_POSITION_LL, (long*) &PresentPos, &error);
            // Read present Velocity
            result = DXL.ReadDWord(DEFAULT_ID, P_PRESENT_VELOCITY_LL, (long*) &PresentVel, &error);
            if( result == COMM_RXSUCCESS )
            {
                printf( "%d   %d\n", GoalVel[index], PresentVel );
                PrintErrorCode(error);
            }
            else
            {
                PrintCommStatus(result);
                break;
            }


        }//while(Moving == 1);*/
        // Change goal position

    }

    // Close device
    DXL.Disconnect();
    printf( "Press Enter key to terminate...\n" );
    _getch();
    return 0;
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

