#include <stdio.h>

int main(void) {
  unsigned int i = 1;

  printf("this is %s endian\n", (*(char *)&i) ? "little" : "big");

  return (0);
}
