#include <stdio.h>
#include <string.h>

int main(void) {
  char s1[32] = "sidde ";
  char s2[] = "gowda";

  strcpy(s1 + strlen(s1), s2);
  printf("new string: %s\n", s1);

  return (0);
}
