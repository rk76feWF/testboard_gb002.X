/*
 * File:   queue.h
 * Author: rk76fewf
 *
 * Created on March 16, 2023, 2:25 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

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

#endif /* QUEUE_H */
