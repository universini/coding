#include<stdio.h>
#include<malloc.h>

int main (void)
{
    int *p;

    p = malloc (0);

    printf ("size: %lu content: %d\n", sizeof(p), *p);

    return (0);
}

