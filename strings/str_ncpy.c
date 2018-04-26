#include <stdio.h>

char* str_ncpy (char *t, const char *s, size_t n)
{
    while (n-- && (*t++ = *s++))
        ;

    return(t);
}

int main (void)
{
    char s1[32];
    char s2[32];

    printf ("enter string (s1): ");
    scanf ("%s", s1);

    str_ncpy(s2, s1, 4);

    printf ("string (s2): %s\n", s2);

    return (0);
}
