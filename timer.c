#include <xc.h>
#include "user.h"

void T2_setup(void);

void TIMER_setup(void)
{
    T2_setup();

    return;
}

void T2_setup()
{
    T2CON = 0x0000;
    T2CONbits.TCKPS = 0b11; // 1:256 prescaler

    PR2 = 1250; // 0.02s period
    _T2IE = 1;  // enable interrupt
    _T2IP = 6;  // interrupt priority
    _T2IF = 0;  // clear interrupt flag

    TMR2 = 0x0000;     // reset timer
    T2CONbits.TON = 1; // start timer

    return;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    LED_Toggle();

    _T2IF = 0; // clear interrupt flag
}
