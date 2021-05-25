#include <stdio.h>

void swap_num(int *a, int *b) {
  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void insert_sort(int a[], int n) {
  int i, j;

  for (i = 1; i < n; i++) {
    j = i;
    while (j > 0 && a[j] < a[j - 1]) {
      swap_num(&a[j], &a[j - 1]);
      j--;
    }
  }

  for (i = 0; i < n; i++) {
    printf(" %d", a[i]);
  }

  printf("\n");

  return;
}

int main(void) {
  int a[] = {2, 3, 7, 4, 8, 1, 9};

  insert_sort(a, 7);
  return (0);
}
