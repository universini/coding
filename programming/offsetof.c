#include <stdio.h>
#include <stdlib.h>

#define OFFSETOF(TYPE, ELEMENT) ((size_t) \
        ((((char *)&((TYPE *)0)->ELEMENT)) - (char *)(TYPE *)0))

#define OFFSETOFPTR(TYPE, ELEMENT)	(size_t)((char *)(&(((TYPE *)0)->ELEMENT)))

#define SIZEOF(t,m)		(sizeof(((t *)0)->m))
#define WORDSOF(x)      (sizeof(x)/sizeof(unsigned int))

typedef struct s_ {
    char  a;
    int   c;
    short b;
}s;

int main (void)
{
    printf ("offset of b: %lu\n", OFFSETOF(s, b));
    printf ("offset of c ptr: %lu\n", OFFSETOFPTR(s, c));
	printf ("Word of c: %lu\n", WORDSOF(s.c));
    return (0);
}

