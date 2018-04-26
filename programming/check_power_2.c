#include <stdio.h>

int main (void)
{
    int n;

    printf ("enter num: ");
    scanf ("%d", &n);

    printf("given num %s power of 2\n", (n && (n-1) == 0) ?"is":"is not");

    return (0);
}

