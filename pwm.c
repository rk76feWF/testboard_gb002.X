#include <xc.h>
#include "user.h"

void OC1_setup(unsigned long);
void OC2_setup(unsigned long);
void OC3_setup(unsigned long);
void OC4_setup(unsigned long);

void PWM_setup(void)
{
    OC1_setup(50000);
    OC2_setup(50000);
    OC3_setup(50000);
    OC4_setup(50000);

    return;
}

void OC1_setup(unsigned long freq)
{
    OC1CON1 = 0b0001110000000110;
    OC1CON2 = 0b0000000000011111;

    _RP4R = 18; // LAN1 7pin
    OC1R = 0;
    OC1RS = (int)(FCY / freq);

    return;
}

void OC2_setup(unsigned long freq)
{
    OC2CON1 = 0b0001110000000110;
    OC2CON2 = 0b0000000000011111;

    _RP7R = 19; // LAN1 8pin
    OC2R = 0;
    OC2RS = (int)(FCY / freq);

    return;
}

void OC3_setup(unsigned long freq)
{
    OC3CON1 = 0b0001110000000110;
    OC3CON2 = 0b0000000000011111;

    _RP11R = 20; // LAN2 7pin
    OC3R = 0;
    OC3RS = (int)(FCY / freq);

    return;
}

void OC4_setup(unsigned long freq)
{
    OC4CON1 = 0b0001110000000110;
    OC4CON2 = 0b0000000000011111;

    _RP10R = 21; // LAN2 8pin
    OC4R = 0;
    OC4RS = (int)(FCY / freq);

    return;
}
