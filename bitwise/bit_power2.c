#include <stdio.h>

int main (void)
{
    int i;

    for (i=0; i<32; i++)
        printf ("2 power of %2u is %10u\n", i, 1<<i);

    return (0);
}
