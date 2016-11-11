/************************************************************ 
Copyright (C) 1995-2002 Pumpkin, Inc. and its
Licensor(s). Freely distributable.
`
$Source: C:\\RCS\\d\\salvo\\tut\\tu1\\isr.c,v $
$Author: aek $
$Revision: 3.22 $
$Date: 2003-07-28 18:41:36-07 $

Source for tutorial programs. Contains the interrupt service
routine and other interrupt-associated code for all of
the tutorials. Organized by compiler and target (SYS*).

************************************************************/

/**
    @file isr.c
    @brief Contains ISRs for @todo xyz
    @author Daniel Tam
    @version 1
    @date November 2016
*/

#include "pconfig.h"
#include "sw_uart_id.h"

#pragma interrupt ISRHigh
void ISRHigh(void)
{
    /* Check if it is the Capture 2 interrupt */
    if(PIE2bits.CCP2IE && PIR2bits.CCP2IF)
    {
        /* Toggle rising/falling edge capture @todo change */
        CCP2CONbits.CCP2M0  = !CCP2CONbits.CCP2M0;
        
        /* Clear possible false interrupt trigger */
        PIR2bits.CCP2IF     = 0;
        
        /* Algorithm */
    }
    
    /* Check if it is the Timer 3 overflow interrupt (stop bit reached) */
    if(PIE2bits.TMR3IE && PIR2bits.TMR3IF)
    {
        PIR2bits.TMR3IF     = 0;
        
        /* Don't need this interrupt until the next start bit is detected */
        PIE2bits.TMR3IE     = 0;
        
        /* Reset Capture 2 for rising edge interrupt to detect start bit */
        CCP2CONbits.CCP2M0  = 1;
        
        /* Clear possible false interrupt trigger */
        PIR2bits.CCP2IF     = 0;
        
        /* Write the rest of the bits somewhere */
        
        /* Reset the counter */
        received_count      = BITSPBYTE;
    }
    
    return;
}

#pragma code IntVectorHigh = 0x08
void IntVectorHigh(void)
{ 	
    _asm
    goto	ISRHigh
    _endasm
}

