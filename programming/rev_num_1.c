#include<stdio.h>

int
reverse(unsigned int n)
{
    int sum = 0;

    while (n) {
	sum = sum * 10 + (n%10);
	n = n/10;
    }

    return(sum);
}

int
main(void)
{
    unsigned int n;

    printf("Enter num: ");
    scanf("%d", &n);
    printf("Reversed num: %u\n", reverse(n));
    return(0);
}
    
