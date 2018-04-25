#include<stdio.h>

int main()
{
    int i, count=0;

    printf("Enter num: ");
    scanf("%d", &i);

    while (i) {
        i = i & (i-1);
        count++;
	}

    printf("Num bits: %u\n", count);
    return(0);
}

