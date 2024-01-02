#include "tinyid.h"

static inline int64_t reverse(int64_t x, int bs)
{
    int b = bs - 1;
    int64_t r = 0;
    for (int i = 0; i < bs; ++i) {
        if (x & (1 << i)) {
            r |= (1 << (b - i));
        }
    }
    return r;
}

static inline int64_t recover(int64_t x, int bs)
{
    int b = bs - 1;
    int64_t r = 0;
    for (int i = 0; i < bs; ++i) {
        if (x & (1 << (b - i)))
            r |= (1 << i);
    }
    return r;
}

static inline int64_t shuffle(int64_t x,
                              int64_t mask,
                              int bs,
                              int64_t (*shuffler)(int64_t, int))
{
    return (x & ~mask) | shuffler(x & mask, bs);
}

static inline int powint(int x, int y)
{
    if (y == 0)
        return 1;
    int r = x;
    while (y > 1) {
        r *= x;
        --y;
    }
    return r;
}

void tinyid_encode(tinyid_t *id, int64_t x, char *buf, int n)
{
    int64_t m = id->al_len;
    x = shuffle(x, id->mask, id->bs, reverse);
    --n;
    while (x > m) {
        *(buf + n) = id->al[x % m];
        x /= m;
        --n;
    }

    *(buf + n) = id->al[x];

    // add paddding
    while (n > 0) {
        --n;
        *(buf + n) = id->al[0];
    }
}

int64_t tinyid_decode(tinyid_t *id, const char *s, int n)
{
    int64_t x = 0;
    int m = id->al_len;
    for (int i = 0; i < n; ++i)
        x += id->indices[s[n - i - 1] - 0x30] * powint(m, i);

    return shuffle(x, id->mask, id->bs, recover);
}

void tinyid_init(tinyid_t *id, int bs, const char *al, int al_len)
{
    // build indices
    for (int i = 0; i < al_len; ++i)
        id->indices[al[i] - 0x30] = i;

    id->al = al;
    id->al_len = al_len;
    id->bs = bs;
    id->mask = (1 << bs) - 1;
}
