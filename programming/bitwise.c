#include <stdio.h>

#define CHAR_BITS 8  // size of character
#define INT_BITS (sizeof(int) * CHAR_BITS)

void print_power(void) {
  int i = 0;

  do {
    printf("%d\n", 1 << i);
  } while (++i < 15);
}

int bit_count_1(unsigned int n) {
  int count;

  count = 0;
  while (n) {
    if (n & 0x01) {
      count++;
    }

    n >>= 1;
  }

  return (count);
}

unsigned int bit_reverse_1(unsigned int n) {
  unsigned int temp = 0;
  int i;

  for (i = 0; i < (INT_BITS - 1); i++) {
    temp |= n & 1;
    n >>= 1;
    temp <<= 1;
  }

  return (temp);
}

unsigned int bit_reverse_2(register unsigned int n) {
  n = (((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1));
  n = (((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2));
  n = (((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4));
  n = (((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8));

  return ((n >> 16) | (n << 16));
}

unsigned int bit_reverse_3(unsigned int n) {
  unsigned int temp = 0;
  int count = 0;

  for (; n > 0; n >>= 1) {
    temp |= n & 1;
    if (n > 1) temp <<= 1;
    count++;
  }

  temp <<= INT_BITS - count;
  return (temp);
}

int bit_count_2(unsigned int n) {
  int count = 0;

  while (n) {
    n = n & (n - 1);
    count++;
  }

  return (count);
}

char *is_bit_set(unsigned int n, int b) {
  return ((n & 1 << b) ? "Yes" : "No");
}

void bit_clear(unsigned int *n, int b) { *n &= ~(1 << b); }

void bit_set(unsigned int *n, int b) { *n |= (1 << b); }

int main(void) {
  unsigned int n = 0xABCD;
  int b;

  printf("Bits set in 0x%X are: %d\n", n, bit_count_1(n));

  printf("Enter bit to be cleared: ");
  scanf("%d", &b);
  bit_clear(&n, b);
  printf("Bits set in 0x%X after cleared bit %d: %d\n", n, b, bit_count_2(n));
  printf("Set bit %d back in 0x%X\n", b, n);
  bit_set(&n, b);
  printf("Bits set in 0x%X after reset bit %d: %d\n", n, b, bit_count_2(n));

  printf("Bit reversed method1: 0x%X\n", bit_reverse_1(11));
  printf("Bit reversed method2: 0x%X\n", bit_reverse_2(11));
  printf("Bit reversed method3: 0x%X\n", bit_reverse_3(11));

  printf("Print power of 2\n");
  print_power();

  while (getchar() != EOF) {
    printf("Enter bit num to check if it is set (Cntrl-C to exit): ");
    scanf("%d", &b);
    printf("Is bit %d set: %s\n", b, is_bit_set(n, b));
  }

  return (0);
}
