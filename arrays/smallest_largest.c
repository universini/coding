#include <stdio.h>
#include <limits.h>

int largest_num(int a[], int n) {
  int large = INT_MIN;

  for (int i = 0; i < n; i++) {
    if (a[i] > large) {
      large = a[i];
    }
  }

  return (large);
}

int smallest_num(int a[], int n) {
  int small = INT_MAX;

  for (int i = 0; i < n; i++) {
    if (a[i] < small) {
      small = a[i];
    }
  }

  return (small);
}

int main(void) {
  int a[] = {8, 5, 1, 3, 7, 4};
  int n = sizeof(a) / sizeof(a[0]);

  printf("small: %d\n", smallest_num(a, n));
  printf("large: %d\n", largest_num(a, n));

  return (0);
}
