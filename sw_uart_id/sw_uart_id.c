/** 
    @file sw_uart_id.c
    @brief Configures interrupts and ports for software UART
    @author Daniel Tam
    @version 1
    @date November 2016

 * This file does the following:
 * SETUP INPUT AND OUTPUT PINS
 * SETUP TIMERS
 * SETUP CCPs
 * TURN ON PRIO
 * SET PRIO HIGH
 * CLEAR INTERRUPT FLAGS
 * ENABLE BOTH CCP INTERRUPTS
 * ENABLE TIMER OVERFLOW INTERRUPTS
 * TURN ON GIEH
*/

#include <pconfig.h>
#include "sw_uart_id.h"

void open_sw_uart(void)
{
    TRIS_SWTXDpin   =   0;
    SWTXDpin        =   0; // Idle low
    SWRXDpin        =   0; // Idle low (shouldn't matter)
    TRIS_SWRXDpin   =   1;
    
    /* Setup Timer 1: 
        16 bit R/W
        1:1 prescaler for maximum resolution
        internal clock (Fosc/4) */
    T1CON           =   0b10000001;
    
    /* Setup Timer 3
        16 bit R/W
        Timer 1 - CCP1, Timer 3 - CCP2
        1:1 prescaler for maximum resolution
        internal clock (Fosc/4) */
    T3CON           =   0b10001001;

    
}