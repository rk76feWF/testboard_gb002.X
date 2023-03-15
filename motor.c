#include <xc.h>
#include "user.h"
#include <math.h>

#define M1S1 _LATA2
#define M1S2 _LATA3
#define M2S1 _LATB5
#define M2S2 _LATA4

#define M3S1 _LATA1
#define M3S2 _LATB2
#define M4S1 _LATB13
#define M4S2 _LATB3

void MOTOR_setup(void)
{
    // LAN1
    _TRISA2 = 0;
    _TRISA3 = 0;
    _TRISB5 = 0;
    _TRISA4 = 0;

    // LAN2
    _TRISA1 = 0;
    _TRISB2 = 0;
    _TRISB13 = 0;
    _TRISB3 = 0;

    return;
}

int motor(int number, double velocity)
{
    bool dir_s1, dir_s2;

    // velocity: -1.0 ~ 1.0
    if (velocity > 1.0 || velocity < -1.0)
        return -1;

    // direction
    if (velocity > 0.0)
        dir_s1 = 1, dir_s2 = 0;
    else if (velocity == 0.0)
        dir_s1 = 0, dir_s2 = 0;
    else
        dir_s1 = 0, dir_s2 = 1;

    switch (number)
    {
    case 1:
        M1S1 = dir_s1;
        M1S2 = dir_s2;
        OC1R = fabs(velocity) * OC1RS;
        break;
    case 2:
        M2S1 = dir_s1;
        M2S2 = dir_s2;
        OC2R = fabs(velocity) * OC2RS;
        break;
    case 3:
        M3S1 = dir_s1;
        M3S2 = dir_s2;
        OC3R = fabs(velocity) * OC3RS;
        break;
    case 4:
        M4S1 = dir_s1;
        M4S2 = dir_s2;
        OC4R = fabs(velocity) * OC4RS;
        break;
    default:
        return -2;
    }

    return 0;
}
