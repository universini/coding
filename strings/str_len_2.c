#include<stdio.h>

int main()
{
    char *s="Sidde";
    char *t=s;

	while(*++t);

    printf("%d\n", (int)(t-s));
    return(0);
}

