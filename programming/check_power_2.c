#include <stdio.h>

int check_power (unsigned int n)
{
    while (n != 1) {
        if (n % 2 != 0) {
            return (0);
        }

        n = n/2;
    }
    
    return (1);
}

int main (void)
{
    unsigned int n;

    printf ("enter num: ");
    scanf ("%d", &n);

    printf("given num %s power of 2\n", check_power(n) ?"is":"is not");

    return (0);
}

