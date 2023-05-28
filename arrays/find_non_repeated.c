#include <stdio.h>

/* In a non-empty array every element appears twice except one. Find it */

int find_single(int a[], int size) {
  int num = a[0];

  for (int i = 1; i < size; i++) {
    num = num ^ a[i];
  }

  return (num);
}

int main(void) {
  int a[] = {2, 2, 3, 3, 4, 4, 5, 6, 6};

  printf("num: %d\n", find_single(a, 9));
  return (0);
}

/*
00
11

11
11

000
100

100
100

000
101

101
110

011
110

101 ->5
*/
