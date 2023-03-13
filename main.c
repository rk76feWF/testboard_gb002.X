#include <xc.h>
#include "config.h"
#include "user.h"

int main(void)
{
    setup();
    int i = 0;
    while (1)
    {
        for (; i < 100; ++i)
        {
            motor(1, (double)i / 100);
            __delay_ms(10);
        }
        for (; i > -100; --i)
        {
            motor(1, (double)i / 100);
            __delay_ms(10);
        }
    }

    return -1;
}
