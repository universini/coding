#include <stdio.h>

#define SIZEOFVAR(v) ((char *)(&v + 1) - (char *)&(v))

struct a {
  int c;
  char d;
};

int main(void) {
  struct a b;
  printf("size of var: %lu\n", SIZEOFVAR(b.c));

  return (0);
}
