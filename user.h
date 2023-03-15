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
#include <stdbool.h>

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
void cartesion_to_polar(int, int, double *, double *);

void MOTOR_setup(void);
int motor(int, double);

typedef struct
{
    // status
    bool connected;
    union
    {
        data_t btn_byte[2];
        struct
        {
            bool Square : 1;
            bool L1 : 1;
            bool L2 : 1;
            bool R1 : 1;
            bool R2 : 1;
            unsigned : 3;
            bool UP : 1;
            bool DOWN : 1;
            bool RIGHT : 1;
            bool LEFT : 1;
            bool Triangle : 1;
            bool Cross : 1;
            bool Circle : 1;
            unsigned : 1;
        } btn;
    };
    struct
    {
        int LStickX;
        int LStickY;
        double LStickR;
        double LStickTheta;

        int RStickX;
        int RStickY;
        double RStickR;
        double RStickTheta;
    } stick;
} ps3_t;

void polar_to_omni4_duty(ps3_t *, double *);
void move(ps3_t *ps3);

#endif /* USER_H */
