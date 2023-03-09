#include <xc.h>
#include "user.h"

void U1_setup(long);
void U2_setup(long);

void UART_setup(void)
{
    U1_setup(38400);
    U2_setup(115100);

    return;
}

void U1_setup(long BRG)
{
    _TRISB9 = 0; // TX pin
    _TRISB8 = 1; // RX pin
    _RP9R = 3;   // TX pin
    _U1RXR = 8;  // RX pin

    U1MODE = 0x0000;
    U1STA = 0x0000;
    U1MODEbits.BRGH = 1; // High speed
    U1BRG = (FCY / (4 * BRG)) - 1;

    _U1RXIE = 1; // Enable RX interrupt
    _U1RXIF = 0; // Clear RX interrupt flag
    _U1RXIP = 7; // Set RX interrupt priority

    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1;   // Enable TX

    return;
}

void U2_setup(long BRG)
{
    _TRISB15 = 0; // TX pin
    _TRISB14 = 1; // RX pin
    _RP15R = 5;   // TX pin
    _U2RXR = 14;  // RX pin

    U2MODE = 0x0000;
    U2STA = 0x0000;
    U2MODEbits.BRGH = 1; // High speed
    U2BRG = (FCY / (4 * BRG)) - 1;

    _U2RXIE = 1; // Enable RX interrupt
    _U2RXIF = 0; // Clear RX interrupt flag
    _U2RXIP = 7; // Set RX interrupt priority

    U2MODEbits.UARTEN = 1; // Enable UART
    U2STAbits.UTXEN = 1;   // Enable TX

    return;
}

void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void)
{
    U1TXREG = U1RXREG;

    _U1RXIF = 0;
}

void __attribute__((__interrupt__, no_auto_psv)) _U2RXInterrupt(void)
{
    U2TXREG = U2RXREG;

    _U2RXIF = 0;
}
