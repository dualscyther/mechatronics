/** \file configReg.h
    \brief Configures the compiler configuration bits. Include BEFORE salvo.h
    \author Daniel Tam
    \version 1
    \date September 2016
    \todo See if we should use XINST to optimize code

 *  This file has to be included BEFORE salvo.h because salvo.h has a #define
 *  for the symbol "OSC", which is also used here.
    Include file to program the configuration registers using the
    'new' type of CONFIG directive.

    The CONFIG directive defines configuration register data from within the
    .c file. Values set here will override those defined in the MPLAB IDE.
    The labels following the directive are defined in the file P18F452.h
    The PIC18FXX2 Data Sheet explains the functions of the configuration bits.

    This file is suitable for debugging; change it to suit your application.

    Note that the directive __CONFIG is deprecated by the CONFIG directive.

    Usage: #include "configReg.h"


    Revision History
       Vers    Date         Who?       Revision Detail?
       1.0     05-Apr-2005  DCR        First release
       2.0     27/09/2016   DT         Second Release
       2.1     13/10/2016   DT         Revised/defined all PIC184520 config bits
*/

#ifndef CONFIGREG_H
#define CONFIGREG_H

#if defined(__18F452)

// Configuration Register 1H
// Oscillator switch disabled, EC oscillator.
// Use OSC = HS or OSC = HSPLL for the minimal board (10MHz/40MHz)
#pragma    config   OSCS=OFF, OSC=EC      // ; for PICDem2 board (4MHz external clock)
// Configuration Register 2L
// Brown-out reset disabled, Brown-out voltage 2.7V, Power-on timer enabled
#pragma    config    BOR=OFF, BORV=27, PWRT=ON

// Program Configuration Register 2H
// Watch-dog Timer disabled, Watch Dog Timer PostScaler count = 1:128
#pragma    config    WDT=OFF, WDTPS=128

// Program Configuration Register 3H
// CCP2 Mux enabled (RC1)
#pragma    config    CCP2MUX=OFF          // ; CCP2 is on RB3 - alternate pin
//#pragma    CONFIG    CCP2MUX=ON          //  ; CCP2 is on RC1 - Default

// Configuration Register 4L
// Stack Overflow Reset enabled, Low Voltage Programming disabled, Debug enabled
#pragma    config    STVR=ON, LVP=OFF, DEBUG=ON

// Configuration Register 5L
// Code protection disabled
#pragma    config    CP0=OFF, CP1=OFF, CP2=OFF, CP3=OFF

// Configuration Register 5H
// Boot block and EEPROM code protection disabled
#pragma    config    CPB=OFF, CPD=OFF

// Configuration Register 6L
// PROM Write protection off
#pragma    config    WRT0=OFF, WRT1=OFF, WRT2=OFF, WRT3=OFF

// Configuration Register 6H
// Config Register, Boot block, EEPROM Write protection off
#pragma    config    WRTC=OFF, WRTB=OFF, WRTD=OFF

// Configuration Register 7L
#pragma    config    EBTR0=OFF, EBTR1=OFF, EBTR2=OFF, EBTR3=OFF

// Configuration Register 7H
// Boot block table read protection off
#pragma    config    EBTRB=OFF

//------------------------------------------------------------------------------
#elif defined(__18F4520)

// CONFIG1H
#pragma config OSC = HS         // Oscillator Selection bits (HS oscillator)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = ON        // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 128      // Watchdog Timer Postscale Select bits (1:128)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))
#pragma config DEBUG = ON       // Configure RB6 and RB7 to dedicated debugging

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

#else
#error Unknown processor!
#endif

#endif