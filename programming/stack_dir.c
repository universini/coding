#include<stdio.h>

void local(int *main)
{
	int local;

	if (main < &local)
		printf("Stack growing upwards\n");
	else
		printf("Stack growing downwards\n");
}

int main(void)
{
	int main;
	local(&main);
	return(0);
}
