#include<stdio.h>

void reverse(int a[], int start, int end)
{
	int temp;

	while (start < end) {
		temp = a[start];
		a[start] = a[end];
		a[end] = temp;
		start++;
		end--;
	}
}

void rotate (int a[], int size)
{
	reverse(a, 0, size);
}

int main(void)
{
	int a[] = {1,2,3,4,5};
	int i;
	int n, k=4;

	rotate(a, 4);
	for (i=0; i<5; i++) {
		printf("%d ", a[i]);
	}

    printf("\n");

	return(0);
}
