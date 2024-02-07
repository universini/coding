#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

#define SIZE_MAX 1000

void print_dups(int a[], int size)
{
    int hash_map[SIZE_MAX] = {false};

    for(int i=0; i<size; i++)
    {
        if (hash_map[a[i]] == true)
        {
            printf("%d ", a[i]);
        }
        hash_map[a[i]] = true;
    }
    printf("\n");
}

int main(void)
{
    int a[] = {1, 2, 3, 3, 4, 5, 5};
    int size = sizeof(a)/sizeof(a[0]);
    print_dups(a, size);
    return 0;
}
