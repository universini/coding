#include<stdio.h>

int pair_sum(int a, int b)
{
	return(a+b);
}

int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int s = sizeof(a)/sizeof(a[0]);
	int sum = 0;

	for (int i=0; i<s; i++) {
		sum = sum + pair_sum(i, i+1);
	}

	printf("Pair sum: %d\n", sum);
	return(0);
}
