/** \file parrot.c
	\brief The main C file for the parrot
	\author Daniel Tam
	\version 1
	\date October 2016
 
	Sends an ASCII 'e' to the XBee every 0.5 seconds.
	XBee must be configured for transparent mode, and
	broadcast mode.
*/

#include "configReg.h"
#include <usart.h>
#include <delays.h>
#include <p18f452.h>
  
/** The main function for the commander */
void main( void )
{
    OpenUSART( USART_TX_INT_OFF & USART_RX_INT_OFF & 
               USART_ASYNCH_MODE & USART_EIGHT_BIT & USART_CONT_RX &
               USART_BRGH_HIGH, 25 );
    for (;;)
    {
        Delay10KTCYx(50);
        while(BusyUSART());
        WriteUSART('e');
    }
}