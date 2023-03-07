/*
 * File:   user.h
 * Author: rk76fewf
 *
 * Created on March 7, 2023, 7:30 AM
 */

#ifndef USER_H
#define USER_H

// delay function
#define FCY 16000000UL
#include <libpic30.h>

// pin definitions
#define LED _LATA0
#define LED_Toggle() LED ^= 1

// function prototypes
void setup(void);
void UART_setup(void);
void TIMER_setup(void);

#endif /* USER_H */
