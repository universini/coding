#include <stdio.h>

void reverse1(int a[], int start, int end) {
  int temp;

  while (start < end) {
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    start++;
    end--;
  }
}

void rotate(int a[], int size) { reverse1(a, 0, size); }

void reverse2(int a[], int sz) {
  int t, x;

  for (int i = 0; i < sz / 2; i++) {
    x = sz - i - 1;
    t = a[i];
    a[i] = a[x];
    a[x] = t;
  }

  for (int i = 0; i < sz; i++) {
    printf("%d ", a[i]);
  }
}

int main(void) {
  int a[] = {1, 2, 3, 4, 5};
  int i;
  int n, k = 4;

  rotate(a, 4);
  for (i = 0; i < 5; i++) {
    printf("%d ", a[i]);
  }

  printf("\n");
  reverse2(a, 5);
  printf("\n");

  return (0);
}
