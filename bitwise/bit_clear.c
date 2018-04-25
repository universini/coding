#include <stdio.h>

int main (void)
{
    unsigned int n;
    int b;

    printf("Enter num: ");
    scanf("%u", &n);

    printf("Enter bit: ");
    scanf("%d", &b);

    n &= ~(1 << (b-1));

    printf ("Number after bit %d is cleared is %u\n", b, n);

    return (0);
}
