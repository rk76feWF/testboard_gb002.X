#include <xc.h>
#include "user.h"

int enqueue(queue_t *q, data_t d)
{
    if (q->size >= MAX_SIZE)
        return -1;

    q->data[(q->head + q->size++) % MAX_SIZE] = d;

    return 0;
}

int dequeue(queue_t *q, data_t *d)
{
    if (q->size <= 0)
        return -1;

    *d = q->data[q->head];

    q->head = (q->head + 1) % MAX_SIZE;
    q->size--;

    return 0;
}
