/*
 * File:   function.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 3:30 AM
 */

#ifndef FUNCTION_H
#define FUNCTION_H

void setup(void);

void UART_setup(void);
void prints(char *);

void TIMER_setup(void);

void PWM_setup(void);
void MOTOR_setup(void);
int motor(int, double);
void polar_to_omni4_duty(ps3_t *, double *);
void move(ps3_t *ps3);

#endif /* FUNCTION_H */
