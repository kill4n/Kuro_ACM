#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "motorinterface.h"
#include "ax_12_motor.h"
using namespace AX_12;
using namespace std;
int main()
{
    MotorInterface *ptrMI;
    AX_12_Motor ax12;
    ptrMI = &ax12;
    int goal = 0;
    ptrMI->setID(18);
    ptrMI->startMotor();
    while(1)
    {
        printf("Definir velocidad -1023,1023 \r\n");
        cin>>goal;
        printf( "Press Enter key to continue!(press ESC and Enter to quit)\n" );
        if(getchar() == 0x1b)
            break;
        //set wheel mode
        ptrMI->setType(JOINT);
        printf( "Succeed to set wheel mode\n" );
        // Write goal position
        //dxl_write_word( DEFAULT_ID, P_GOAL_POSITION_L, GoalPos[index] );
        ptrMI->moveMotor(goal);
       /* do
        {
            // Read present position
            PresentPos = dxl_read_word( DEFAULT_ID, P_PRESENT_POSITION_L );
            CommStatus = dxl_get_result();

            if( CommStatus == COMM_RXSUCCESS )
            {
                printf( "%d   %d\n",GoalPos[index], PresentPos );
                PrintErrorCode();
            }
            else
            {
                PrintCommStatus(CommStatus);
                break;
            }

            // Check moving done
            Moving = dxl_read_byte( DEFAULT_ID, P_MOVING );
            CommStatus = dxl_get_result();
            if( CommStatus == COMM_RXSUCCESS )
            {
                if( Moving == 0 )
                {
                    // Change goal position
                    if( index == 0 )
                        index = 1;
                    else
                        index = 0;
                }

                PrintErrorCode();
            }
            else
            {
                PrintCommStatus(CommStatus);
                break;
            }
        }while(Moving == 1);*/
    }
    // Close device
    ptrMI->stopMotor();
    printf( "Press Enter key to terminate...\n" );
    getchar();
    return 0;
}
