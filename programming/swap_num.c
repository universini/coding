#include <stdio.h>

int main (void)
{
    int a = 10, b = 20;

    printf ("a: %d b: %d\n", a, b);
    a^=b;
    b^=a;
    a^=b;
    printf ("a: %d b: %d\n", a, b);

    return (0);
}
