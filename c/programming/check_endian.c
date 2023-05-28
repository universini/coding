#include <stdio.h>

typedef union u_ {
  char c;
  unsigned int i;
} u_t;

int main(void) {
  u_t u;

  u.i = 0x1;

  if (*(char *)&(u.c)) {
    printf("Little endian\n");
  } else {
    printf("Big endian\n");
  }

  unsigned int i = 1;
  printf("%s endian\n", (*(char *)&i) ? "Little" : "Big");

  return (0);
}
