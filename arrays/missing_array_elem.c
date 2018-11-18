#include <stdio.h>

int main (void)
{
    int a[] = {1,2,3,5,6,7,8,9};
    int n = sizeof (a)/sizeof (a[0]);
    int sum = 0;
    int i;
    
    sum = (n+1) * (n+2)/2; //+1 for a missing num from n*(n+1)/2
    for (i=0; i<n; i++) {
        sum -= a[i];
    }
        
    printf ("missing no: %d\n", sum);
    
    return (0);
}
