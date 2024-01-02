#include <stdint.h>
#include <stdio.h>
#include "tinyid.h"

int main()
{
    int64_t x = 10000;
    int n = 4;
    char s[n];
    tinyid_t id;
    tinyid_init(&id, TINYID_BS, TINYID_AL, TINYID_AL_LEN);
    tinyid_encode(&id, x, s, n);
    printf("%s\n", s);
    int64_t y = tinyid_decode(&id, s, n);
    if (x != y) {
        printf("want %lld, but got %lld\n", x, y);
        return -1;
    }
    return 0;
}
