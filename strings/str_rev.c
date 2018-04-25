#include <stdio.h>
#include <string.h>

void rev_str (char *s)
{
    int i, j, c;
    int len = strlen(s)-1;

    for (i=0, j=len; i<j; i++, j--) {
        c = *(s+i);
        *(s+i) = *(s+j);
        *(s+j) = c;
    }
}
        
int main (void)
{
    char s[]="sidde gowda";

    printf ("original: %s\n", s);
    rev_str(s);
    printf ("reversed: %s\n", s);

    return (0);
}
