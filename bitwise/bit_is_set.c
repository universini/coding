#include<stdio.h>

char*
is_bit_set(unsigned int n, int b)
{
	return((n & 1<<b)?"yes":"no");
}

int main(void)
{
	unsigned int n;
	int b;

	printf("Enter num: ");
    scanf("%u", &n);
	printf("Enter bit position: ");
    scanf("%d", &b);
	printf("Is bit %d set: %s\n", b, is_bit_set(n, b-1));

	return(0);
}

