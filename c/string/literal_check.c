#include <stdio.h>
#include <string.h>

int main(void) {
  char *s1 = "Sidde";
  char *t1;
  char s2[] = "Gowda";

  printf("s1: %s s2: %s\n", s1, s2);

  t1 = s1;
  s2[3] = 'r';

  printf("t1: %s s2: %s\n", t1, s2);

  t1 = s2;

  printf("t1: %s\n", t1);

  *(s1 + 4) = 'u';

  printf("s1: %s\n", s1);

  return (0);
}
