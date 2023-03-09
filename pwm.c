#include <xc.h>
#include "user.h"

void OC1_setup(unsigned long);

void PWM_setup(void)
{
    OC1_setup(50000);

    return;
}

void OC1_setup(unsigned long freq)
{
    OC1CON1 = 0b0001110000000110;
    OC1CON2 = 0b0000000000011111;

    _RP4R = 18;
    OC1R = 0;
    OC1RS = (int)(FCY / freq);

    return;
}
