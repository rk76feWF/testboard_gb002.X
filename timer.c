#include <xc.h>
#include "user.h"

void T2_setup(int, int);

static inline unsigned short int get_tckps(int prescaler);

extern queue_t u1;
extern ps3_t ps3;

void TIMER_setup(void)
{
    // (1/16000000) * prescaler * period

    T2_setup(256, 125); // (1/16000000) * 256 * 125 = 0.002s

    return;
}

void T2_setup(int prescaler, int period)
{
    unsigned short int TCKPS = get_tckps(prescaler);

    // エラー処理
    if (TCKPS == -1 || period > 65535)
        return;

    T2CON = 0x0000;
    T2CONbits.TCKPS = TCKPS; // 1:256 prescaler

    PR2 = period; // set period
    _T2IE = 1;    // enable interrupt
    _T2IP = 6;    // interrupt priority
    _T2IF = 0;    // clear interrupt flag

    TMR2 = 0x0000;     // reset timer
    T2CONbits.TON = 1; // start timer

    return;
}

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void)
{
    static int counter = 0;

    // タイムアウト処理
    if (counter > 100)
    {
        LED_SetHigh();
        ps3.connected = false;
    }
    else
    {
        LED_SetLow();
        ++counter;
    }

    if (ps3_read(&u1) == 0)
        counter = 0;

    _T2IF = 0; // clear interrupt flag
}

static inline unsigned short int get_tckps(int prescaler)
{
    switch (prescaler)
    {
    case 1:
        return 0b00;
    case 8:
        return 0b01;
    case 64:
        return 0b10;
    case 256:
        return 0b11;
    default:
        return -1;
    }
}
