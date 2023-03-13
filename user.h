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
void prints(char *);
void TIMER_setup(void);
void PWM_setup(void);

// queue
typedef unsigned char data_t;
#define MAX_SIZE 128

typedef struct
{
    data_t data[MAX_SIZE];
    int head;
    int size;
} queue_t;

int enqueue(queue_t *, data_t);
int dequeue(queue_t *, data_t *);

#endif /* USER_H */
