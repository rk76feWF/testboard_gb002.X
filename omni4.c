#include <xc.h>
#include "user.h"

void move(ps3_t *ps3)
{
    double duty[4] = {0.0, 0.0, 0.0, 0.0};

    if (ps3->connected)
        polar_to_omni4_duty(ps3, duty);

    motor(1, duty[0]);
    motor(2, duty[1]);
    motor(3, duty[2]);
    motor(4, duty[3]);

    return;
}

void polar_to_omni4_duty(ps3_t *ps3, double *duty)
{
    double theta = ps3->stick.LStickTheta;
    double r = ps3->stick.LStickR;

    duty[0] = cos((135 - theta) * (M_PI / 180)) * r / 64.0;
    duty[1] = -cos((theta - 45) * (M_PI / 180)) * r / 64.0;
    duty[2] = -duty[0];
    duty[3] = -duty[1];

    return;
}
