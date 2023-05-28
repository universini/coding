#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void str_check(char **s, char *t) {
  int c = 1, i = 0;

  while (**s != 0) {
    printf("%c: %d\n", **s, **s);
    *(t + i) = *(*s);
    (*s)++;
    i++;
  }

  c += i;
  printf("%c: %d\n", **s, **s);
  printf("len: %d\n", c);
  t[i] = '\0';
}

int main(void) {
  char *s, t[12];

  s = malloc(12);

  strcpy(s, "siddeg0wda4");
  *(s + 11) = 0;

  str_check(&s, t);
  puts(t);

  printf("Last char: %lu:%d\n", strlen(t), t[strlen(t) - 1] - '0');

  return (0);
}
