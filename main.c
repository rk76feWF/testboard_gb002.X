#include <xc.h>
#include "config.h"
#include "user.h"

int main(void)
{
    setup();
    while (1)
    {
        // LED_Toggle();
        __delay_ms(500);
    }

    return -1;
}
