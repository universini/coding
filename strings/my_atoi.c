#include <stdio.h>
#include <string.h>

int main(void) {
  char s[] = "12345";
  int i = 0;
  int num = 0;

  while (s[i] != '\0') {
    num = num * 10 + (s[i++] - '0');
  }

  printf("atoi of \"%s\" is %d\n", s, num);

  return (0);
}
