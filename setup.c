#include <xc.h>
#include "user.h"

void setup(void)
{
    OSCCON = 0x0000;
    CLKDIV = 0x0000;
    AD1PCFG = 0xffff;

    TRISA = 0xffff;
    TRISB = 0xffff;

    _TRISA0 = 0; // LED

    UART_setup();
    TIMER_setup();
    MOTOR_setup();
    PWM_setup();

    return;
}
