#include <stdio.h>
#include <stdlib.h>

struct n {
  char a;
  double c;
  int b;
};

struct m {
  double c;
  int b;
  char a;
};

int main(void) {
  printf("size1: %lu size2: %lu\n", sizeof(struct n), sizeof(struct m));

  return (0);
}
