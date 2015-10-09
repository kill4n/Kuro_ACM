/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************

#include "app.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
 */

APP_DATA appData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback funtions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary local functions.
 */

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize(void) {
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

    /* TODO: Initialize your application's state machine and other
     * parameters.
     */
}

/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */
int i;

void sendMessage() {
    unsigned char chk = 0;
    DRV_USART0_WriteByte(appData.mensajeTx.cmd);
    chk = appData.mensajeTx.cmd;
    DRV_USART0_WriteByte(appData.mensajeTx.nDatos);
    chk += appData.mensajeTx.nDatos;
    for (i = 0; i < appData.mensajeTx.nDatos; i++) {
        DRV_USART0_WriteByte(appData.mensajeTx.Datos[i]);
        chk += appData.mensajeTx.Datos[i];
    }
    chk = chk ^ appData.mensajeTx.cmd;
    appData.mensajeTx.cksum = chk;
    DRV_USART0_WriteByte(appData.mensajeTx.cksum);
}

void APP_Tasks(void) {
    /* Check the application's current state. */
    switch (appData.state) {
            /* Application's initial state. */
        case APP_STATE_INIT:
        {
            DRV_USART0_Initialize();
            DRV_OC0_Start();
            DRV_OC1_Start();
            DRV_OC2_Start();

            DRV_TMR0_Start();
            DRV_TMR1_Start();
            appData.state = APP_STATE_IDLE;


            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
            break;
        }

            /* TODO: implement your application state machine.*/

        case APP_STATE_SERIAL_EVENT:
        {
            if (appData.mensajeRx.cmd == 0xA1) {
                switch (appData.mensajeRx.Datos[0]) {
                    case 1:
                    {
                        if (appData.mensajeRx.Datos[1] == 1)//Sentido de Giro Motor 1
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_1);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_1);
                        if (appData.mensajeRx.Datos[2] == 1)//Freno Motor1
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_0);
                        OC1RS = (250 * (appData.mensajeRx.Datos[3]));
                        break;
                    }
                    case 2:
                    {
                        if (appData.mensajeRx.Datos[1] == 1)//Sentido de Giro Motor 2
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_2);
                        if (appData.mensajeRx.Datos[2] == 1)//Freno Motor2
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_1);
                        OC2RS = (250 * (appData.mensajeRx.Datos[3]));
                        break;
                    }
                    case 3:
                    {
                        if (appData.mensajeRx.Datos[1] == 1)//Sentido de Giro Motor 3
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_3);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_3);
                        if (appData.mensajeRx.Datos[2] == 1)//Freno Motor3
                            PLIB_PORTS_PinSet(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_0);
                        else
                            PLIB_PORTS_PinClear(PORTS_ID_0, PORT_CHANNEL_B, PORTS_BIT_POS_0);
                        OC3RS = (250 * (appData.mensajeRx.Datos[3]));
                        break;
                    }
                    default:
                        break;
                }                
            }

            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_TIMER_EVENT:
        { //1 ms -> 360 pulsos = 400 rpm

            appData.mensajeTx.cmd = (unsigned char) 0xB1;
            appData.mensajeTx.nDatos = 5;
            appData.mensajeTx.Datos[0] = (unsigned char) (appData.puls1 * 255 / 360);
            appData.mensajeTx.Datos[1] = (unsigned char) (appData.puls2 * 255 / 360);
            appData.mensajeTx.Datos[2] = (unsigned char) (appData.puls3 * 255 / 360);
            LATAbits.LATA0 = !LATAbits.LATA0;
            sendMessage();

            appData.puls1 = 0;
            appData.puls2 = 0;
            appData.puls3 = 0;
            appData.state = APP_STATE_IDLE;

            break;
        }
        case APP_STATE_INT1_EVENT:
        {
            appData.puls1++;
            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_INT2_EVENT:
        {
            appData.puls2++;
            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_INT3_EVENT:
        {
            appData.puls3++;
            appData.state = APP_STATE_IDLE;
            break;
        }
        case APP_STATE_IDLE:
        {
            break;
        }
            /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
