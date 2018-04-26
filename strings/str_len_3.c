#include <stdio.h>

int str_len_ptr (const char *s)
{
    const char *p = s;

    while (*++s) ;

    return (s-p);
}

int main (void)
{
    char s[] = "Sidde Gowda";

    printf ("len: %d\n", str_len_ptr(s));
    printf ("str: %s\n", s);

    return (0);
}
