/** \file sw_uart_delays.c
	\brief Implements delay functions for the C18 library for the sw_uart
	\author Daniel Tam
	\version 1
	\date October 2016
*/

#include <delays.h>

#if defined(__18F452)

void DelayRXHalfBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (8*BAUD_RATE)) + 1) / 2) - 9;
    // approx 44 cycles on the 18F452
    Delay10TCYx(4);
}

void DelayTXBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (4*BAUD_RATE)) + 1) / 2) - 12;
    // approx 93 cycles on 18F452
    Delay10TCYx(8);   
    _asm
            NOP NOP
            NOP NOP
            NOP NOP
            NOP NOP
            NOP
    _endasm
    
}

void DelayRXBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (4*BAUD_RATE)) + 1) / 2) - 14;
    // approx 91 cycles on 18F452
    Delay10TCYx(8);
    _asm
            NOP NOP
            NOP NOP
            NOP NOP
            NOP
    _endasm
    
}

#elif defined(__18F4520)

void DelayRXHalfBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (8*BAUD_RATE)) + 1) / 2) - 9;
    // approx 122 cycles on the 18F4520
    Delay100TCYx(1);
    Delay10TCYx(1);
    _asm
            NOP NOP
            NOP NOP
            NOP NOP
            NOP NOP
    _endasm
}

void DelayTXBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (4*BAUD_RATE)) + 1) / 2) - 12;
    // approx 249 cycles on 18F4520
    Delay100TCYx(2);
    Delay10TCYx(4);   
    _asm
            NOP
            NOP
            NOP
            NOP
            NOP
    _endasm
    
}

void DelayRXBitUART(void)
{
    //int num_cycles = ((((2*FOSC) / (4*BAUD_RATE)) + 1) / 2) - 14;
    // approx 247 cycles on 18F4520
    Delay100TCYx(2);
    Delay10TCYx(4);
    _asm
            NOP
            NOP
            NOP
    _endasm
    
}

#else
#error Unknown processor!
#endif
