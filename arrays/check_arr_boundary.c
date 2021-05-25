#include <stdio.h>

int main(void) {
  int a[10];

  a[10] = 1;
  a[-2] = 2;

  printf("a[10] = %d a[-2] = %d\n", a[10], a[-2]);

  return (0);
}
