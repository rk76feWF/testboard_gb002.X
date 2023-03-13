#include <xc.h>
#include "config.h"
#include "user.h"

int main(void)
{
    setup();
    while (1)
    {
        __delay_ms(1);
    }

    return -1;
}
