/* 
    @file sw_uart_id.h
    @brief Defines the pins used and ... @todo
    @author Daniel Tam
    @version 1
    @date November 2016
 * 
 * NOTE: User must define instruction cycles/bit (baud rate) and pins used
 * 
 * @todo: Assumptions, robustness/error checking
 * 
 * This module will use:
 * - 2 interrupts for transmission: Timer1 overflow and Compare1 (on Timer1)
 * - 2 interrupts for receiving: Timer3 overflow and Capture2 (on Timer3)

 */

#ifndef SW_UART_ID_H
#define	SW_UART_ID_H

#include <pconfig.h>

/** Choose how many instruction cycles elapse per bit sent/received 
   @todo see what sort of precision is required?*/
#define CYCLESPERBIT        104 // Should be 104.1666...

/** Choose which pins are used for transmission */
#define SWTXDpin            LATDbits.LATD6        
#define TRIS_SWTXDpin       TRISDbits.TRISD6

/** Choose which pins are used for reception - Either RC1 or RB3 (CCP2) 
    @todo probably don't need this */
#define SWRXDpin            PORTCbits.RC1
#define TRIS_SWRXDpin       TRISCbits.TRISC1

/** The algorithm assumes 1 start bit and 1 stop bit + 8 data bits */
#define BITSPBYTE           10

/** Global denoting how many bits have currently been received */
extern volatile unsigned char received_count;

/** Global denoting how many bits have currently been transmitted */
extern volatile unsigned char transmit_count;

void open_sw_uart_receive(void);
void open_sw_uart_transmit(void);

#endif	/* SW_UART_ID_H */

