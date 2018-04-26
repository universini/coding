#include <stdio.h>

char* str_cpy (char *t, const char *s)
{
    while (*t++ = *s++)
        ;

    return(t);
}

int main (void)
{
    char s1[32];
    char s2[32];

    printf ("enter string (s1): ");
    scanf ("%s", s1);

    str_cpy(s2, s1);

    printf ("string (s2): %s\n", s2);

    return (0);
}
