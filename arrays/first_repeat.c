#include <stdio.h>
#include <limits.h>

int first_dup(int a[], int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (a[i] == a[j]) {
        return (a[i]);
      }
    }
  }

  return (-1);
}

int main(void) {
  int a[] = {8, 5, 1, 3, 7, 4, 5};
  int n = sizeof(a) / sizeof(a[0]);

  printf("first dup: %d\n", first_dup(a, n));

  return (0);
}
