#include <stdio.h>

int str_len_1(const char *s) {
  const char *t = s;

  while (*++s)
    ;

  return (s - t);
}

int str_len_2(const char *s) {
  int i = 0;

  while (s[i++])
    ;

  return (--i);
}

int main(void) {
  char s[] = "Sidde Gowda";

  printf("String len method1: %d\n", str_len_1(s));
  printf("String len method2: %d\n", str_len_2(s));

  return (0);
}
