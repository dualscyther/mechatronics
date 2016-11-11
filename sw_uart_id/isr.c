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

/** \file isr.c
	\brief Contains ISR for Salvo and hardware serial transmission/reception. 
	\author Neill Foweraker, Daniel Tam
	\version 1
	\date October 2016
*/

#include "isr.h"
#include <salvo.h>
#ifdef _COMMANDER
    #include "../commander.X/interface.h"
    #include "../commander.X/salvo_labels_commander.h"
    #include "../commander.X/rf_commander.h"
    #include "../shared/tpro/tpro.h"
#endif
#ifdef _ROBOT
    #include "../robot.X/rf_robot.h"
    #include "../robot.X/encoders.h"
    #include "../robot.X/salvo_labels_robot.h"
#endif

#include "USART/usart.h"
#include "../shared/buffer.h"

#include <pconfig.h>

#if   defined(USE_INTERRUPTS)

#if defined(SYSE)

#pragma interrupt ISRHigh


void ISRHigh( void )
{
    char d;
    
    if ( INTCONbits.TMR0IE && INTCONbits.TMR0IF )
    {
        INTCONbits.TMR0IF = 0;
        TMR0L -= TMR0_RELOAD;

        OSTimer();
    }
    
    if(DataRdyUSART())
    {
        
        d = ReadUSART();
        
#ifdef _COMMANDER
        if(interface_serialpassthrough)
        {
            if(interface_passthroughsize == 0)
            {
                interface_passthroughsize = d;
                // save the size of the current tpro packet
                buffer_write_next(  &packet_size_buffer, 
                        interface_passthroughsize);
            }
            else
            {
                --interface_passthroughsize;
                buffer_write_next(&RF_encode_queue, d);
                
                if(!interface_passthroughsize)
                {
                    // let the RF module know we are ready to transmit
                    OSSignalSem(SEM_ENCODE_READY);
                }
                
            }
        }
        else
        {
            buffer_write_next(&hardware_serial_in, d);            
        }
                    
#endif
            
#ifdef _ROBOT
        buffer_write_next(&hardware_serial_in, d);
        OSSignalSem(SEM_DECODE_READY);
#endif
        //return;
    }
    else if(PIR1bits.TXIF) // Output anything in the serial out buffer if we have anything to send
    {
        if(buffer_has_unread(&hardware_serial_out))
        {
            putcUSART(buffer_read_next(&hardware_serial_out));
            //return;
        }
        else
        {
            PIE1bits.TXIE = 0;
        }
    }
    
#ifdef _COMMANDER //\todo collaborate with Neil (set flags?)
    //button 1 RB0 interrupt
    if (INTCONbits.INT0IF) 
    {
        button_A_pressed = true;
        //clear RB0 flag bit   
        INTCONbits.INT0IF = 0; 
    }
    
    //button 2 RB1 interrupt 
    if (INTCON3bits.INT1IF) 
    {
        button_B_pressed = true;
        //clear RB1 flag bit  
        INTCON3bits.INT1IF = 0;   
    }
#endif
    
    /* Encoder Interrupts */
#ifdef _ROBOT
    
     //encoder 1 RB0 interrupt --> LEFT WHEEL
    if (INTCONbits.INT0IF) 
    {
        ++encoders_left_ISR_count;    
        INTCONbits.INT0IF = 0; //clear RB0 flag bit 
    }
    
    //encoder 2 RB1 interrupt --> RIGHT WHEEL
    if (INTCON3bits.INT1IF) 
    {
        ++encoders_right_ISR_count;
        INTCON3bits.INT1IF = 0; //clear RB1 flag bit  
    }
    
    if (PIR1bits.TMR1IF)
    {
        PIR1bits.TMR1IF = 0;
        
        // Store the change in counter since last interrupt
        encoders_left_dcount_actual = encoders_left_ISR_count;
        encoders_left_ISR_count = 0;        
        encoders_right_dcount_actual = encoders_right_ISR_count;
        encoders_right_ISR_count = 0;
        
        // Tell the PID controller to run
        OSSignalBinSem(BINSEM_TIMER_ONE_TICK);
    }

#endif    
    
    
}

#pragma code IntVectorHigh = 0x08
void IntVectorHigh( void )
{ 	
    _asm
    goto	ISRHigh
    _endasm
}



#else /* SYS* not defined */

#error Undefined Salvo test system (SYS*). Definition required.

#endif

#endif

