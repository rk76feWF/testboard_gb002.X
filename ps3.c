#include <xc.h>
#include <stdlib.h>
#include "user.h"

void ps3_read(queue_t *q)
{
    data_t frame[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    if (dequeue(q, &frame[0]) == -1)
        return;

    // frameのサイズと先頭のバイトが正しいか確認
    if (q->size != (8 - 1) || frame[0] != 0x80)
    {
        // 一度全部捨てる
        q->size = 0;
        q->head = 0;
        return;
    }

    // 0x80以外のデータを取り出す
    for (int i = 1; i < 8; ++i)
        dequeue(q, &frame[i]);

    // Frame Check Sequence
    {
        data_t fcs = 0;
        for (int i = 1; i < 8 - 1; ++i)
            fcs += frame[i];

        if ((fcs & 0x7F) != frame[8 - 1])
            return;
    }

    // debug
    {
        char str[64];
        sprintf(str, "data: 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x 0x%02x\n", frame[0], frame[1], frame[2], frame[3], frame[4], frame[5], frame[6], frame[7]);
        prints(str);
    }

    return;
}
