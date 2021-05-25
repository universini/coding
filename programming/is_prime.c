#include <stdio.h>

int is_prime(int n) {
  int i;

  if (n <= 1) return (0);

  for (i = 2; i <= n / 2; i++) {
    if (n % i == 0) {
      i = 1;
      break;
    }
  }

  if (i == 1)
    return (0);
  else
    return (1);
}

int main(void) {
  int n;

  printf("Enter number: ");
  scanf("%d", &n);
  printf("Number is %s\n", is_prime(n) ? "prime" : "not a prime");
  return (0);
}
