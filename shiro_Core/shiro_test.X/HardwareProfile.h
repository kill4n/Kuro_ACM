/* 
 * File:   HardwareProfile.h
 * Author: crhistian
 *
 * Created on September 14, 2015, 5:54 PM
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#include <xc.h>
#include <p32xxxx.h>

#pragma config FNOSC = FRCPLL           // Oscillator Selection Bits (Fast RC Osc with PLL)
#pragma config FPLLIDIV = DIV_2 // Divide FRC before PLL (now 4 MHz)
#pragma config FPLLMUL = MUL_20 // PLL Multiply (now 80 MHz)
#pragma config FPLLODIV = DIV_2 // Divide After PLL (now 40 MHz)

#pragma config FWDTEN = OFF         // Disable watchdog timer
#pragma config ICESEL = ICS_PGx1    // select pins to transfer program data on (ICSP pins)
#pragma config FSOSCEN = OFF        // Disable secondary oscillator
#pragma config JTAGEN = OFF         // Disable JTAG

#pragma config FPBDIV = DIV_1           // Peripheral Clock Divisor (Pb_Clk is Sys_Clk)

#define SYSCLK 40000000
#define PBCLK 40000000


#endif	/* HARDWAREPROFILE_H */