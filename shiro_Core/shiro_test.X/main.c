/*
 * File:   main.c
 * Author: crhistian
 *
 * Created on September 14, 2015, 5:52 PM
 */

#include "HardwareProfile.h"

//Rename and Tris
#define SG1 LATAbits.LATA0
#define SG2 LATAbits.LATA1
#define SG3 LATBbits.LATB3

#define FR1 LATBbits.LATB15
#define FR2 LATBbits.LATB14
#define FR3 LATBbits.LATB13

#define PWM_FREQ    16000
void PWM_1(int Duty_Cycle) {
    OC1CON = 0x0006;
    PR2 = (PBCLK / PWM_FREQ) - 1;
    OC1RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
    T2CONbits.ON = 1; // Enable Timer2, prescaler 1:1
    OC1CONbits.ON = 1; // Enable Output Compare Module 1
}
void PWM_2(int Duty_Cycle) {
    OC2CON = 0x0006;
    PR2 = (PBCLK / PWM_FREQ) - 1;
    OC2RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
    T2CONbits.ON = 1; // Enable Timer2, prescaler 1:1
    OC2CONbits.ON = 1; // Enable Output Compare Module 2
}
void PWM_3(int Duty_Cycle) {
    OC3CON = 0x0006;
    PR2 = (PBCLK / PWM_FREQ) - 1;
    OC3RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
    T2CONbits.ON = 1; // Enable Timer2, prescaler 1:1
    OC3CONbits.ON = 1; // Enable Output Compare Module 3
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

const int pwm_duty_cycles[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
#define ARRAY_SIZE               (sizeof(pwm_duty_cycles))

void main(void) {
    ANSELA = 0; //Port A Digital
    ANSELB = 0; //Port B Digital

    defineTRIS();
    mapPins();

    int i = 0, j = 0;
    SG1 = 0;
    int tim = 50000;
    while (1) {
        FR1 = 1;
        FR2 = 0;
        FR3 = 1;
        PWM_1(pwm_duty_cycles[j]);
        PWM_2(100-pwm_duty_cycles[j]);
        PWM_3(pwm_duty_cycles[(int)(j/2)]);
        j++;
        for (i = 0; i < tim; i++);
        FR1 = 0;
        FR2 = 1;
        FR3 = 0;
        for (i = 0; i < tim; i++);

        if (j >= 11)
            j = 0;
    }
}