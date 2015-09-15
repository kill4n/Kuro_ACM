/* 
 * File:   newfile.h
 * Author: killan
 *
 * Created on 14 de septiembre de 2015, 08:57 AM
 */
#include <xc.h>
#include <xc.h>
#include "p32xxxx.h"

#ifndef HARDWARE_PROFILE_H
#define	HARDWARE_PROFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

    //Configuracion Bits 8 MHz interno clock 40M
#pragma config FSOSCEN = OFF        // Disable secondary oscillator

#pragma config FNOSC = FCRPLL   // Internal Fast RC oscillator (8 MHz) w/ PLL
#pragma config FPLLIDIV = DIV_2 // Divide FRC before PLL (now 4 MHz)
#pragma config FPLLMUL = MUL_20 // PLL Multiply (now 80 MHz)
#pragma config FPLLODIV = DIV_2 // Divide After PLL (now 40 MHz)

#pragma config FWDTEN = OFF             // Watchdog Timer Enable (WDT Disabled (SWDTEN Bit Controls))
#pragma config JTAGEN = OFF             // Disable JTAG
#pragma config ICESEL = ICS_PGx1    // select pins to transfer program data on (ICSP pins)

#pragma config FPBDIV = DIV_1      //Sets PBCLK to SYSCLK
    
#define SYSCLK      (40000000)
#define SYS_FREQ    (SYSCLK)
#define PBCLK       (SYSCLK)

#ifdef	__cplusplus
}
#endif

#endif	/* HARDWARE_PROFILE_H */

