#include <stdio.h>

unsigned int n1 = 1234;

int main (void)
{
    unsigned int n2 = 0;

    while (n1 > 0) {
        n2 = n2 + n1%10;
        n1 = n1/10;

        if (n1 != 0) {
            n2 = n2*10;
        }
    }

    printf ("reversed num = %u\n", n2);

    return (0);
}

