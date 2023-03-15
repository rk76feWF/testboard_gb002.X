#include <xc.h>
#include "config.h"
#include "user.h"

extern ps3_t ps3;

int main(void)
{
    setup();
    char str[64];
    while (1)
    {
        sprintf(str, "%03d %03d %03d %03d\n", ps3.stick.LStickX, ps3.stick.LStickY, ps3.stick.RStickX, ps3.stick.RStickY);
        // sprintf(str, "%d %d %d %d %d %d %d %d %d %d %d %d\n", ps3.btn.Square, ps3.btn.L1, ps3.btn.L2, ps3.btn.R1, ps3.btn.R2, ps3.btn.UP, ps3.btn.DOWN, ps3.btn.RIGHT, ps3.btn.LEFT, ps3.btn.Triangle, ps3.btn.Cross, ps3.btn.Circle);
        prints(str);
    }

    return -1;
}
