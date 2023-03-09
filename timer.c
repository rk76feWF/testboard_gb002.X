#include <xc.h>
#include "user.h"

void T2_setup(int, int);

void TIMER_setup(void)
{
    // (1/16000000) * prescaler * period

    // (1/16000000) * 256 * 1250 = 0.02s
    T2_setup(256, 1250);

    return;
}

void T2_setup(int prescaler, int period)
{
    T2CON = 0x0000;

    unsigned short int TCKPS = 0;
    switch (prescaler)
    {
    case 1:
        TCKPS = 0b00;
        break;
    case 8:
        TCKPS = 0b01;
        break;
    case 64:
        TCKPS = 0b10;
        break;
    case 256:
        TCKPS = 0b11;
        break;
    default:
        return;
    }

    if (period > 65535)
        return;

    T2CONbits.TCKPS = TCKPS; // 1:256 prescaler

    PR2 = period; // period
    _T2IE = 1;    // enable interrupt
    _T2IP = 6;    // interrupt priority
    _T2IF = 0;    // clear interrupt flag

    TMR2 = 0x0000;     // reset timer
    T2CONbits.TON = 1; // start timer

    return;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    LED_Toggle();

    _T2IF = 0; // clear interrupt flag
}
