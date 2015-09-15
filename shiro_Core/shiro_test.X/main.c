/*
 * File:   main.c
 * Author: crhistian
 *
 * Created on September 14, 2015, 5:52 PM
 */

/******************************************************************************
 * Software License Agreement
 *
 * Copyright � 2011 Microchip Technology Inc.  All rights reserved.
 * Microchip licenses to you the right to use, modify, copy and distribute
 * Software only when embedded on a Microchip microcontroller or digital
 * signal controller, which is integrated into your product or third party
 * product (pursuant to the sublicense terms in the accompanying license
 * agreement).
 *
 * You should refer to the license agreement accompanying this Software
 * for additional information regarding your rights and obligations.
 *
 * SOFTWARE AND DOCUMENTATION ARE PROVIDED ìAS ISî WITHOUT WARRANTY OF ANY
 * KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY
 * OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR
 * PURPOSE. IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR
 * OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION,
 * BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT
 * DAMAGES OR EXPENSES INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL,
 * INDIRECT, PUNITIVE OR CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA,
 * COST OF PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY
 * CLAIMS BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
 * OR OTHER SIMILAR COSTS.
 *
 *****************************************************************************/

#include "HardwareProfile.h"

//Rename and Tris
#define SG1 LATAbits.LATA0
#define SG2 LATAbits.LATA1
#define SG3 LATBbits.LATB3

#define FR1 LATBbits.LATB15
#define FR2 LATBbits.LATB14
#define FR3 LATBbits.LATB13

#define PWM_FREQ    16000
#define DUTY_CYCLE  10

void PWM_1_6(){
    // Configure standard PWM mode for output compare module 1
    OC1CON = 0x0006; 
    // A write to PRy configures the PWM frequency
    // PR = [FPB / (PWM Frequency * TMR Prescale Value)] ? 1
    // : note the TMR Prescaler is 1 and is thus ignored
    PR2 = (SYSCLK / PWM_FREQ) - 1;
 
    // A write to OCxRS configures the duty cycle
    // : OCxRS / PRy = duty cycle
    OC1RS = (PR2 + 1) * ((float)DUTY_CYCLE / 100);
 
    T2CONSET = 0x8000;      // Enable Timer2, prescaler 1:1
    OC1CONSET = 0x8000;     // Enable Output Compare Module 1
}

void defineTRIS() {
    TRISAbits.TRISA0 = 0; //SG1
    TRISAbits.TRISA1 = 0; //SG2
    TRISBbits.TRISB3 = 0; //SG3

    TRISBbits.TRISB15 = 0; //FR1
    TRISBbits.TRISB14 = 0; //FR2
    TRISBbits.TRISB13 = 0; //FR3
}

void mapPins() {
    RPB7R = 0b0101; // OC1
    RPB11R = 0b0101; // OC2
    RPB10R = 0b0101; // OC3
}

void main(void) {
    ANSELA = 0; //Port A Analog
    ANSELB = 0; //Port B Analog

    defineTRIS();

    SG1 = 0;
    while (1);
}