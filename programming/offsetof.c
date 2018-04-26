#include <stdio.h>

#define OFFSETOF(TYPE, ELEMENT) ((size_t) \
        ((((char *)&((TYPE *)0)->ELEMENT)) - (char *)(TYPE *)0))

typedef struct s_ {
    int   a;
    char  b;
    short c;
}s;

int main (void)
{
    printf ("offset if b: %lu\n", OFFSETOF(s, b));
    return (0);
}

