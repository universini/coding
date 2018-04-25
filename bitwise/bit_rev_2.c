#include <stdio.h>

#define ENDIAN_CONV(x) (((x) & 0xff000000) >> 24 | \
                        ((x) & 0x00ff0000) >> 8  | \
                        ((x) & 0x0000ff00) << 8  | \
                        ((x) & 0x000000ff) << 24)

int main (void)
{
    unsigned int i = 0x01020304;

    printf ("before: 0x%x after: 0x%x\n", i, ENDIAN_CONV(i));

    return (0);
}
