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
#define LED_SetLow() LED = 0
#define LED_SetHigh() LED = 1
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

int ps3_read(queue_t *);

void MOTOR_setup(void);
int motor(int, double);

typedef struct
{
    union
    {
        data_t btn_byte[2];
        struct
        {
            _Bool Square : 1;
            _Bool L1 : 1;
            _Bool L2 : 1;
            _Bool R1 : 1;
            _Bool R2 : 1;
            unsigned : 3;
            _Bool UP : 1;
            _Bool DOWN : 1;
            _Bool RIGHT : 1;
            _Bool LEFT : 1;
            _Bool Triangle : 1;
            _Bool Cross : 1;
            _Bool Circle : 1;
            unsigned : 1;
        } btn;
    };
    struct
    {
        int LStickX;
        int LStickY;
        int RStickX;
        int RStickY;
    } stick;
} ps3_t;

#endif /* USER_H */
