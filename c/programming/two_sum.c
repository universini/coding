#include <stdio.h>

int two_sum(int a[], int num, int len) {
  int start = 0;
  int end = len - 1;
  int sum = 0;

  while (start < end) {
    sum = a[start] + a[end];
    if (sum == num)
      return (1);
    else if (sum < num)
      start++;
    else
      end--;
  }

  return (0);
}

int main(void) {
  int a[] = {1, 2, 4, 6, 7, 9};
  int len = sizeof(a) / sizeof(a[0]);

  printf("%s\n", two_sum(a, 13, len) ? "True" : "False");
  return (0);
}
