#include <stdio.h>

int main (void)
{
    int a;
    int i;
    int c = 0;

    scanf ("%d", &a);
    for (i=0; i<8*sizeof(int); i++){
        if (a&1) c++;
        a>>=1;
    }

    printf ("Num bits: %d\n", c);
}
