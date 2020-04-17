#include<stdio.h>

void print_union (int a[], int b[], int m, int n)
{
	int i = 0, j = 0;

	while (i<m && j<n) {
		if (a[i] < b[j]) {
			printf(" %d ", a[i]);
			i++;
		} else if (a[i] > b[j]) {
			printf(" %d ", b[j]);
			j++;
		} else {
			printf(" %d ", a[i]);
			i++;
			j++;
		}
	}

	while (i<m) printf(" %d ", a[i++]);
	while (j<n) printf(" %d ", b[j++]);

	return;
}

int main(void)
{
	int a[] = {2,4,5,7,8,9};
	int b[] = {1,2,3,6,8,9,11};
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);

	printf("{");
	print_union(a,b,m,n);
	printf("}\n");

	return(0);
}

