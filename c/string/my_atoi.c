#include <stdio.h>
#include <string.h>

int my_atoi(const char *s) {
  int sign = 1;
  int i = 0;
  int num = 0;

  if (*(s + i) == '-') {
    i++;
    sign = -1;
  }

  while (*(s + i) != '\0') {
    num = num * 10 + (*(s + i) - '0');
    i++;
  }

  return num * sign;
}

int main(void) {
  char s[] = "12345";
  int i = 0;
  int num = 0;

  while (s[i] != '\0') {
    num = num * 10 + (s[i++] - '0');
  } // doesn't work for -ve numbers

  printf("atoi of \"%s\" is %d\n", s, num);
  printf("atoi of \"%s\" is %d\n", s, my_atoi(s));

  return (0);
}
