/** 
    @file main.c
    @brief Test file. Enables interrupt priorities and global interrupts.
    @author Daniel Tam
    @version 1
    @date November 2016
 */

#include "sw_uart_id.h"

/** Test function */
void main(void) {
    
    /* Enable interrupt priority levels */
    RCONbits.IPEN   = 1;
    
    /* Enable high priority interrupts */
    INTCONbits.GIEH = 1;
    
    open_sw_uart_receive();
    
    while(1);
}

