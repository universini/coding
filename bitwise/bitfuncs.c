#include<stdio.h>

int
num_bits_set1(unsigned int n)
{
	int count;

	count = 0;
	while (n) {
		if (n & 0x01) {
			count++;
		}

		n >>= 1;
	}

	return(count);
}

int
num_bits_set2(unsigned int n)
{
	int count = 0;

	while(n) {
		n = n & (n-1);
		count++;
	}

	return(count);
}

char *
is_bit_set(unsigned int n, int b)
{
	return((n & 1<<b)?"Yes":"No");
}

int
main(void)
{
	unsigned int n = 0xABCD;
	int b;

	printf("Count1: %d\n", num_bits_set1(n));
	printf("Count2: %d\n", num_bits_set2(n));
	printf("Hit return to continue ...");
	while (getchar() != EOF) {
		printf("Enter bit position to check (Cntrl-C to exit): ");
		scanf("%d", &b);
		printf("Is bit %d set: %s\n", b, is_bit_set(n, b));
	}

	return(0);
}

