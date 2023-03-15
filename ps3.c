#include <xc.h>
#include <stdio.h>
#include "user.h"
#include <math.h>

ps3_t ps3;

int ps3_read(queue_t *q)
{
    data_t frame[8] = {0, 0, 0, 0, 0, 0, 0, 0};

    // queueにデータが格納されていることを確認
    if (dequeue(q, &frame[0]) == -1)
        return -1;

    // frameのサイズと先頭のバイトが正しいか確認
    if (q->size != (8 - 1) || frame[0] != 0x80)
    {
        // 一度全部捨てる
        q->size = 0;
        q->head = 0;
        return -2;
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
            return -3;
    }

    // データをps3_tに格納
    {
        ps3.btn_byte[0] = frame[1];
        ps3.btn_byte[1] = frame[2];

        ps3.stick.LStickX = -64 + frame[3];
        ps3.stick.LStickY = 64 - frame[4];
        ps3.stick.RStickX = -64 + frame[5];
        ps3.stick.RStickY = 64 - frame[6];
    }

    // 極座標変換
    {
        cartesion_to_polar(ps3.stick.LStickX, ps3.stick.LStickY, &ps3.stick.LStickR, &ps3.stick.LStickTheta);
        cartesion_to_polar(ps3.stick.RStickX, ps3.stick.RStickY, &ps3.stick.RStickR, &ps3.stick.RStickTheta);
    }

    ps3.connected = true;

    return 0;
}

void cartesion_to_polar(int x, int y, double *r, double *theta)
{
    *r = sqrt(x * x + y * y);
    if (*r > 64)
        *r = 64;

    // 無駄な計算を省略
    if (x == 0 && y == 0)
    {
        *theta = 0;
        return;
    }

    *theta = (atan2(y, x) * 180 / M_PI);

    return;
}
