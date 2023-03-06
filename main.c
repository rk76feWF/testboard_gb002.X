#include <xc.h>
#include "config.h"
#define FCY 16000000UL
#include <libpic30.h>

#define LED _LATA0
#define LED_Toggle() LED ^= 1

void setup(void);

int main(void)
{
    setup();
    while (1)
    {
        LED_Toggle();
        __delay_ms(500);
    }

    return 0;
}

void setup(void)
{
    OSCCON = 0x0000;
    CLKDIV = 0x0000;
    AD1PCFG = 0xffff;

    TRISA = 0xffff;
    TRISB = 0xffff;

    _TRISA0 = 0;
}
