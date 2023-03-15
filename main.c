#include <xc.h>
#include "config.h"
#include "user.h"

extern ps3_t ps3;

int main(void)
{
    setup();

    while (1)
    {
        move(&ps3);
    }

    return -1;
}
