#include<stdio.h>

int bsearch(int a[], int n, int max)
{
    int min = 0;

    while (min <= max) {
        int mid;
        mid = (min + max)/2;

        if (n < a[mid]) {
            max = mid-1;
        } else if (n > a[mid]) {
            min = mid+1;
        } else {
            return (mid);
        }
    }

    return(-1);
}
        
int main(void)
{
    int a[] = {1, 3, 5, 8, 45, 51, 78, 91, 100};
    int l = sizeof(a)/sizeof(a[0]);
    int n;

    printf("Enter number rto be searched: ");
    scanf("%d", &n);
    printf("position = %d\n", bsearch(a, n, l));

    return(0);
}

