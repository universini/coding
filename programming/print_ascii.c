#include <stdio.h>

void print (int i)
{

    if (i >= 128) {
        return;
    } else {
        printf ("%d -> %c\n", i, i);
        print (i+1);
    }
}

int main (void)
{
    int i = 32;
    print (i);
    
    return (0);
}
    
