#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "motores/motorinterface/include/motorinterface.h"
#include "motores/AX_12/include/ax_12_motor.h"
using namespace AX_12;
using namespace std;
int main()
{
    MotorInterface *ptrMI1,*ptrMI2,*ptrMI3,*ptrMI4,*ptrMI5,*ptrMI6;
    AX_12_Motor ax12_1,ax12_2,ax12_3,ax12_4,ax12_5,ax12_6;
    ptrMI1 = &ax12_1;
    ptrMI2 = &ax12_2;
    ptrMI3 = &ax12_3;
    ptrMI4 = &ax12_4;
    ptrMI5 = &ax12_5;
    ptrMI6 = &ax12_6;

    int goal = 0;
    ptrMI1->setID(7);ptrMI1->startMotor();ptrMI1->setType(WHEEL);
    ptrMI2->setID(8);ptrMI2->startMotor();ptrMI2->setType(WHEEL);
    ptrMI3->setID(9);ptrMI3->startMotor();ptrMI3->setType(WHEEL);
    ptrMI4->setID(10);ptrMI4->startMotor();ptrMI4->setType(WHEEL);
    ptrMI5->setID(11);ptrMI5->startMotor();ptrMI5->setType(WHEEL);
    ptrMI6->setID(12);ptrMI6->startMotor();ptrMI6->setType(WHEEL);


    while(1)
    {
        printf("Definir velocidad -1023,1023 \r\n");
        cin>>goal;
        printf( "Press Enter key to continue!(press ESC and Enter to quit)\n" );
        if(getchar() == 0x1b)
            break;
        //set wheel mode

        printf( "Succeed to set wheel mode\n" );
        // Write goal position
        //dxl_write_word( DEFAULT_ID, P_GOAL_POSITION_L, GoalPos[index] );
        ptrMI1->moveMotor(goal);
        ptrMI2->moveMotor(-goal);
        ptrMI3->moveMotor(goal);
        ptrMI4->moveMotor(-goal);
        ptrMI5->moveMotor(goal);
        ptrMI6->moveMotor(-goal);
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
    ptrMI1->stopMotor();
    ptrMI2->stopMotor();
    ptrMI3->stopMotor();
    ptrMI4->stopMotor();
    ptrMI5->stopMotor();
    ptrMI6->stopMotor();
    printf( "Press Enter key to terminate...\n" );
    getchar();
    return 0;
}
