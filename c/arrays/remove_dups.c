#include <stdio.h>

int remove_dups(int a[], int n) {
  int t[n];
  int j = 0;

  if (n <= 1) {
    return (n);
  }

  for (int i = 0; i < n; i++) {
    if (a[i] != a[i + 1]) {
      t[j++] = a[i];
    }
  }

  for (int i = 0; i < j; i++) {
    a[i] = t[i];
  }

  printf("\n");

  return (j);
}

int main(void) {
  int a[] = {1, 2, 5, 5, 6, 6, 7, 8};
  int n = sizeof(a) / sizeof(a[0]);

  n = remove_dups(a, n);

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");

  return (0);
}
