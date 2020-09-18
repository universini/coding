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
        
void rev_str_rec (char *s, int start, int end)
{
	char ch;

	if (start >= end)
		return;

	ch = *(s+start);
	*(s+start) = *(s+end);
	*(s+end) = ch;

	rev_str_rec(s, ++start, --end);
}

int main (void)
{
    char s[]="sidde gowda";

    printf ("original: %s\n", s);
    rev_str(s);
    printf ("reversed: %s\n", s);
    rev_str_rec(s, 0, strlen(s)-1);
    printf ("original: %s\n", s);

    return (0);
}
