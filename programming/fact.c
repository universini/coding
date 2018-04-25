#include<stdio.h>

int fact1(int n)
{
    if (n == 0) return 1;
    else return (n*fact1(n-1));
}

int fact2(int n)
{
    int fact = 1;
    int i;

    for (i=1; i<=n; i++)
        fact = fact*i;

    return fact;
}

int main (void)
{
    int n;

    printf ("enter num: ");
    scanf ("%d", &n);

    printf ("fact1: %d fact2: %d\n", fact1(n), fact2(n));

    return (0);
}
