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

#include "sw_uart_id.h"

#pragma interrupt ISRHigh
void ISRHigh(void)
{
    return;
}

#pragma code IntVectorHigh = 0x08
void IntVectorHigh(void)
{ 	
    _asm
    goto	ISRHigh
    _endasm
}

