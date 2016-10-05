/** \file xlcd_delays.c
	\brief Implements delay functions for the C18 library for the LCD screen
	\author Daniel Tam
	\version 1
	\date September 2016
*/

/** Delay for 18 cycles. Uses 14 NOP assembly commands
    since it takes 4 cycles to enter and exit the function. */
void DelayFor18TCY(void)
{
    _asm
        NOP NOP NOP NOP
        NOP NOP NOP NOP
        NOP NOP NOP NOP
        NOP NOP
    _endasm
}

#if defined(__18F452)

/** Delay for 15 milliseconds, which is 15000 cycles on a 4 MHz processor
 *  as the instruction rate is /4 i.e. 1 MHz */        
void DelayPORXLCD(void)
{
    int i = 1151;
    
    // These NOP commands precisely tune the function to 15000 cycles and
    // disable compiler optimization
    _asm NOP NOP NOP NOP NOP NOP NOP _endasm
            
    // This loop takes 13 cycles each iteration (checking, entering, exiting)
    while(i)
    {
        --i;
    }           
}
        
/** Delay for 5 milliseconds, which is 5000 cycles on a 4 MHz processor
 *  as the instruction rate is /4 i.e. 1 MHz */         
void DelayXLCD(void)
{
    int i = 382;
    
    // These NOP commands precisely tune the function to 5000 cycles and
    // disable compiler optimization
    _asm NOP NOP NOP NOP _endasm
            
    // This loop takes 13 cycles each iteration (checking, entering, exiting)
    while(i)
    {
        --i;
    }        
}

#elif defined(__18F4520)

/** Delay for 15 milliseconds, which is 37500 cycles on a 10 MHz processor
 *  as the instruction rate is /4 i.e. 2.5 MHz */          
void DelayPORXLCD(void)
{
    int i = 2882;
    
    // These NOP commands precisely tune the function to 37500 cycles and
    // disable compiler optimization
    _asm
        NOP NOP NOP NOP
    _endasm
            
    // This loop takes 13 cycles each iteration (checking, entering, exiting)
    while(i)
    {
        --i;
    }           
}
        
/** Delay for 5 milliseconds, which is 12500 cycles on a 10 MHz processor
 *  as the instruction rate is /4 i.e. 2.5 MHz */          
void DelayXLCD(void)
{
    int i = 959;
    
    // These NOP commands precisely tune the function to 12500 cycles and
    // disable compiler optimization
    _asm
        NOP NOP NOP
    _endasm
            
            
    // This loop takes 13 cycles each iteration (checking, entering, exiting)
    while(i)
    {
        --i;
    }        
}

#else
#error Unknown processor!
#endif
