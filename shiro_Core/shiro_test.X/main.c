/*
 * File:   main.c
 * Author: crhistian
 *
 * Created on September 14, 2015, 5:52 PM
 */
#include "HardwareProfile.h"
//Rename Pins
#define SG1 LATAbits.LATA0
#define SG2 LATAbits.LATA1
#define SG3 LATBbits.LATB3
#define FR1 LATBbits.LATB15
#define FR2 LATBbits.LATB14
#define FR3 LATBbits.LATB13
//PWM Frecuencia
#define PWM_FREQ    16000
//Métodos

void PWM_Config() {
    //Definir los PWMs
    OC1CON = 0x0006;
    OC2CON = 0x0006;
    OC3CON = 0x0006;
    //Definir Frecuencia
    PR2 = (PBCLK / PWM_FREQ) - 1;
    //Habilitar PWMs
    OC1CONbits.ON = 1; // Enable Output Compare Module 1
    OC2CONbits.ON = 1; // Enable Output Compare Module 2
    OC3CONbits.ON = 1; // Enable Output Compare Module 3
    //Habilitar Timer2
    T2CONbits.ON = 1; // Enable Timer2, prescaler 1:1
}

void PWM_1(int Duty_Cycle) {
    OC1RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
}

void PWM_2(int Duty_Cycle) {
    OC2RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
}

void PWM_3(int Duty_Cycle) {
    OC3RS = (PR2 + 1) * ((float) Duty_Cycle / 100);
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

void initConf() {
    ANSELA = 0; //Port A Digital
    ANSELB = 0; //Port B Digital

    defineTRIS();
    mapPins();
}
const int pwm_duty_cycles[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
#define ARRAY_SIZE               (sizeof(pwm_duty_cycles))
//variables
#define SLAVE_ADDRESS 0x40

void InitI2c() {
    I2C1CON = 0;
    //I2C1CONbits.SCLREL = 1;
    I2C1CONbits.STREN = 1; //Estira la trama
    I2C1CONbits.ON = 1; //Start I2C
    I2C1CONbits.A10M = 0; //Address 7bits
    I2C1BRG = 0xC2; //40MHz -> 100k
    I2C1AADD = SLAVE_ADDRESS; //Cargar Direccion del Slave
    I2C1MSK = 0;
}

void main(void) {
    initConf();
    InitI2c();
    while (1) {

    }
}