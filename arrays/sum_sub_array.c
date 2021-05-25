#include <stdio.h>
#include <stdlib.h>

int sum_sub(int a[], int l) {
  int total = 0;

  for (int i = 0; i < l; i++) {
    int sum = 0;
    for (int j = i; j < l; j++) {
      sum += a[j];
      total += sum;
    }
  }

  return (total);
}

int main(void) {
  int a[] = {1, 3, 7};
  int l = sizeof(a) / sizeof(a[0]);

  printf("sum sub array: %d\n", sum_sub(a, l));
  return (0);
}
