#include<stdio.h>

int main()
{
    unsigned int i=10;

	printf("%u\n", i);
    printf("%u\n", i |= (1<<2));
    printf("%u\n", i &= ~(1<<2));

	return(0);
}

