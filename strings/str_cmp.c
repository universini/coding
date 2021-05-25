#include <stdio.h>
#include <string.h>

int str_cmp(char *s1, char *s2) {
  while (*s1 == *s2)
    if (*s1 == '\0' || *s2 == '\0')
      return (0);
    else {
      s1++;
      s2++;
    }

  return (*s1 - *s2);
}

int main(void) {
  char s[] = "sidde";
  char t[] = "siddego";

  printf("str_cmp returned: %d\n", str_cmp(s, t));

  return (0);
}
