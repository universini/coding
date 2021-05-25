#include <stdio.h>

int main(void) {
  int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = sizeof(a) / sizeof(a[0]);
  int t, i, j = 0;

  for (i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");

  for (i = 0; i < n; i++) {
    if (a[i] % 2 == 0) {
      t = a[i];
      a[i] = a[j];
      a[j] = t;
      j++;
    }
  }

  for (i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");

  return (0);
}
