#include <stdio.h>

int power1 (int base, int pow)
{
    int sum = 1;
    int i;

    for (i=0; i<pow; i++)
        sum=sum*base;

    return (sum);
}

int power2 (int base, int pow)
{
    if (pow == 0)
        return 1;
    else return (base*power2(base, pow-1));
}

int main (void)
{
    int b;

    printf ("enter num: ");
    scanf ("%d", &b);

    printf ("power1 : %d power2: %d\n", power1(2, b), power2(2, b));

    return (0);
}
