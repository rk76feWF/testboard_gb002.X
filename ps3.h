/*
 * File:   ps3.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 2:27 AM
 */

#ifndef PS3_H
#define PS3_H

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

int ps3_read(queue_t *);
void cartesion_to_polar(int, int, double *, double *);

#endif /* PS3_H */
