#ifndef TINYID_
#define TINYID_

#define TINYID_AL "JedR8LNFY2j6MrhkBSADUyfP5amuH9xQCX4VqbgpsGtnW7vc3TwKE"
#define TINYID_AL_LEN 53
#define TINYID_BS 24
#define TINYID_MASK ((1 << TINYID_BS) - 1)

#include <stdint.h>

typedef struct tinyid {
    int bs;
    int64_t mask;
    int64_t al_len;
    const char *al;
    int indices[75];
} tinyid_t;

void tinyid_init(tinyid_t *, int, const char *, int);
void tinyid_encode(tinyid_t *, int64_t, char *, int);
int64_t tinyid_decode(tinyid_t *, const char *, int);

#endif  // TINYID_