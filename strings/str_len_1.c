#include <stdio.h>

int main (void)
{
    char s[256];
    int  i=0;

    printf ("enter string: ");
    scanf ("%s", s);

    while (s[++i] != '\0');

    printf ("length: %d\n", i);

    return (0);
}
