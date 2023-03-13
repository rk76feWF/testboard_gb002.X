#include <xc.h>
#include "config.h"
#include "user.h"

extern queue_t u1;

int main(void)
{
    setup();
    while (1)
    {
        data_t d;
        if (dequeue(&u1, &d) == 0)
            U2TXREG = d;
    }

    return -1;
}
