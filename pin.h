/*
 * File:   pin.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 2:29 AM
 */

#ifndef PIN_H
#define PIN_H

// LED
#define LED _LATA0
#define LED_SetLow() LED = 0
#define LED_SetHigh() LED = 1
#define LED_Toggle() LED ^= 1

// LAN1
#define M1S1 _LATA2
#define M1S2 _LATA3
#define M2S1 _LATB5
#define M2S2 _LATA4
// LAN2
#define M3S1 _LATA1
#define M3S2 _LATB2
#define M4S1 _LATB13
#define M4S2 _LATB3

#endif /* PIN_H */
