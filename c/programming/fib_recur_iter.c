#include <stdio.h>

int fibonacci_iter(int n) {
  int first = 0, second = 1, next, c;

  for (c = 0; c < n; c++) {
    if (c <= 1)
      next = c;
    else {
      next = first + second;
      first = second;
      second = next;
    }
    printf("%d\n", next);
  }
}

int fibonacci_recur(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return (fibonacci_recur(n - 1) + fibonacci_recur(n - 2));
}

int main(void) {
  int n, i = 0, c;

  printf("Enter number: ");

  scanf("%d", &n);

  printf("Recursive:\n");
  for (c = 1; c <= n; c++) {
    printf("%d\n", fibonacci_recur(i));
    i++;
  }

  printf("Iterative:\n");
  fibonacci_iter(n);

  return 0;
}