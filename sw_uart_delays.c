/** \file sw_uart_delays.c
	\brief Implements delay functions for the C18 library for sw_uart
	\author Daniel Tam
	\version 1
	\date October 2016
*/

#include <delays.h>

#if defined(__18F452)

/* Delay for:
((((2*FOSC) / (8*baud)) + 1) / 2) - 9 cycles */
void DelayRXHalfBitUART(void)
{
    // 4.52 (5) cycles on the 18F4520
    _asm NOP _endasm
}

/* Delay for:
((((2*FOSC) / (4*baud)) + 1) / 2) - 12 cycles */
void DelayTXBitUART(void)
{
    // 14.54 cycles (15) (it takes 4 cycles to enter and exit the function)
    Delay10TCYx(1);
    _asm NOP _endasm
}

/* Delay for:
((((2*FOSC) / (4*baud)) + 1) / 2) - 14 cycles */
void DelayRXBitUART(void)
{
    // 12.54 cycles (13) (it takes 4 cycles to enter and exit the function)
    _asm
            NOP NOP
            NOP NOP
            NOP NOP
            NOP NOP
            NOP
    _endasm
}

#elif defined(__18F4520)

/* Delay for:
((((2*FOSC) / (8*baud)) + 1) / 2) - 9 cycles */
void DelayRXHalfBitUART(void)
{
    // 24.05 cycles on the 18F4520 (rounded down to 24)
    Delay10TCYx(2);
}

/* Delay for:
((((2*FOSC) / (4*baud)) + 1) / 2) - 12 cycles */
void DelayTXBitUART(void)
{
    // 53.6 cycles (54) (it takes 4 cycles to enter and exit the function)
    Delay10TCYx(5);
}

/* Delay for:
((((2*FOSC) / (4*baud)) + 1) / 2) - 14 cycles */
void DelayRXBitUART(void)
{
    // 51.6 cycles (52) (it takes 4 cycles to enter and exit the function)
    Delay10TCYx(4);
    _asm
            NOP NOP
            NOP NOP
            NOP NOP
            NOP NOP
    _endasm
}

#else
#error Unknown processor!
#endif
