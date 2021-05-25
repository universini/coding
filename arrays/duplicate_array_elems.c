#include <stdio.h>
#include <stdlib.h>

void print_dup(int a[], int sz) {
  int *c;
  int i;

  c = (int *)calloc(sizeof(int), sz);

  for (i = 0; i < sz; i++) {
    if (c[a[i]] == 1) {
      printf("%d ", a[i]);
    } else {
      c[a[i]]++;
    }
  }

  printf("\n");

  return;
}

int main(void) {
  int a[] = {1, 5, 6, 2, 5, 4, 2, 6, 8};
  int s = sizeof(a) / sizeof(a[0]);

  print_dup(a, s);

  return (0);
}
