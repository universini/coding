#include<stdio.h>

int main()
{
    int i;
    int count=0;

    printf("Enter num: ");
    scanf("%d", &i);

    while (i) {
        if (i&0x1) count++;
        i>>=1;
    }

    printf("Num bits: %d\n", count);
    return(0);
}

