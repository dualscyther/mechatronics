/** 
 *  @file sw_uart_id.c
 *  @brief Configures interrupts and ports for software UART
 *  @author Daniel Tam
 *  @version 1
 *  @date November 2016
 * 
 * Assumptions: INTCON.GIEH and RCON.IPEN set
 *
 * This file does the following:
 * SETUP INPUT AND OUTPUT PINS
 * SETUP TIMERS
 * SETUP CCPs
 * SET PRIO HIGH
 * CLEAR INTERRUPT FLAGS
 * ENABLE BOTH CCP INTERRUPTS
 * ENABLE TIMER OVERFLOW INTERRUPTS
*/

#include <pconfig.h>
#include "sw_uart_id.h"

/* These could actually just be defined and declared static in isr.c */
volatile unsigned char received_count            = BITSPBYTE;
volatile unsigned char received_byte_current     = 0;
volatile unsigned char received_byte             = 0;
volatile unsigned char received_byte_ready       = 0;

volatile unsigned char transmit_count   = BITSPBYTE;

/** Configures ports and interrupts for receiving software UART */
void open_sw_uart_receive(void) {

    SWRXDpin        = 0;
    TRIS_SWRXDpin   = 1;
    
    /* Setup Timer 3
     *  16 bit R/W
     *  Timer 1 - CCP1, Timer 3 - CCP2
     *  1:1 prescaler for maximum resolution
     *  internal clock (Fosc/4) 
     */
    T3CON = 0b10001001;

    /* Setup Capture 2 (capture every rising edge) */
    CCP2CON = 0b00000101;
    
    /* Enable high priorities on Timer 3 and CCP2 interrupts */
    IPR2bits.CCP2IP = 1;
    IPR2bits.TMR3IP = 1;
    
    /* Clear interrupt flags for Timer 3 and CCP2 */
    PIR2bits.CCP2IF = 0;
    PIR2bits.TMR3IF = 0;
    
    /* Initialise counter */
    received_count = BITSPBYTE;
    
    /* Enable interrupt on CCP2 */
    PIE2bits.CCP2IE = 1;
    
    /* Disable interrupt on Timer 3 overflow (for now) */
    PIE2bits.TMR3IE = 0;
    
    return;
}

/** Configures ports and interrupts for transmitting software UART 
    @todo unfinished */
void open_sw_uart_transmit(void) {

    TRIS_SWTXDpin = 0;
    SWTXDpin = 0;
    
    /* Setup Timer 3
     *  16 bit R/W
     *  Timer 1 - CCP1, Timer 3 - CCP2
     *  1:1 prescaler for maximum resolution
     *  internal clock (Fosc/4) 
     *  TODO: need to use T3CON to setup this one too, whatdo? 
     */
    T3CON = 0b10001001;
    
    /* Setup Timer 1: 
        16 bit R/W
        1:1 prescaler for maximum resolution
        internal clock (Fosc/4) */
    T1CON = 0b10000001;

    /* Setup Compare 1 (idle clear, set on match) */
    CCP1CON = 0b00001000;    
            
    return;        
}
