#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int a[] = {1,2,3,4,5,5,6,7,7,8,9,9,10};
    int n = sizeof (a)/sizeof (a[0]);
	int nums[n];
    int i;
    
    for (i=0; i<n; i++) {
		if (nums[a[i]] == 1) {
			printf("%d ", a[i]);
		} else {
			nums[a[i]]++;
		}
	}

	printf("\n");

    return (0);
}
