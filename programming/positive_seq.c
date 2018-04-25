#include <stdio.h>

int find_seq (int arr[],
              int len,
              int num)
{
    int sum = 0;
    int i, j;
    
    for (i=0, j=0; i<len; i++) {
    
        sum+=arr[i];
        
        if (sum > num) {
            sum-=arr[j];
            j++;
        }
        
        if (sum == num) return (1);
    }
    
    return (0);
}

int main (void)
{
    int arr[] = {1,3,5,7,9};
    int len = sizeof(arr)/sizeof(arr[0]);
    
    printf ("%s sequence for num 8\n",
            find_seq(arr, len, 8)?"found":"not found");
    
    return (0);
}

