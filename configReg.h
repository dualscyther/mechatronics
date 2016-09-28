/** \file configReg.h
    \brief Configures the compiler configuration bits. Include BEFORE salvo.h
    \author Daniel Tam
    \version 1
    \date September 2016

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

// Configuration Register 1H
// Oscillator switch disabled, EC oscillator.
// Use OSC = HS or OSC = HSPLL for the minimal board (10MHz/40MHz)
#pragma    config       OSC=HS      // ; for the minimal board
// Configuration Register 2L
// Brown-out reset disabled, Brown-out voltage 2.7V, Power-on timer enabled
#pragma    config    BOREN=OFF, PWRT=ON

// Program Configuration Register 2H
// Watch-dog Timer disabled, Watch Dog Timer PostScaler count = 1:128
#pragma    config    WDT=OFF, WDTPS=128

// Program Configuration Register 3H
// CCP2 Mux enabled (RC1)
//#pragma    config    CCP2MX=PORTBE          // ; CCP2 is on RB3 - alternate pin
#pragma    config    CCP2MX=PORTC          //  ; CCP2 is on RC1 - Default

// Configuration Register 4L
// Stack Overflow Reset enabled, Low Voltage Programming disabled, Debug enabled
#pragma    config    STVREN=ON, LVP=OFF, DEBUG=ON

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

#else
#error Unknown processor!
#endif

#endif