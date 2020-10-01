#include<stdio.h>

int sum_num (int n) {
    if (n <= 0) return (0);
    return n + sum_num(n-1); /* 5+4, 4+3, 3+2, 2+1, 1+0 */
}

int sumn (int a, int b) {
    return ((a)+(b));
}

int sum_pair (int n) {
    int sum = 0;

    for (int i=0; i<n; i++) {
	    sum+=sumn(i, i+1);
    }

	   return (sum);
}

int main(void)
{
    int n=5;

	    printf ("Sum1: %d\n", sum_num(n));
	    printf ("Sum2: %d\n", sum_pair(n));

	    return (0);
}

