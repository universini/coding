#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int a[] = {1,2,3,4,5,5,6,7,8,9,10};
    int n = sizeof (a)/sizeof (a[0]);
    int sum1 = n*(n-1)/2; //-1 for 1 duplicate
    int sum2 = 0;
    int i;
    
    for (i=0; i<n; i++)
        sum2+=a[i];

    printf ("1st method: %d\n", sum2-sum1);
    
    for (i=0; i<n; i++)
        sum1-=a[i];

    printf ("2nd method: %d\n", abs(sum1));
    
    return (0);
}
