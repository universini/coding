#include <stdio.h>
#include <string.h>

int str_n_cmp(const char *s1, const char *s2, size_t sz) {
  while (sz--) {
    if (*s1 != *s2) {
      return (*s1 - *s2);
    }

    s1++;
    s2++;
  }

  return (0);
}

int main(void) {
  char s1[] = "Sidde";
  char s2[] = "Siddu";

  printf("Strings %s and %s are %s\n", s1, s2,
         str_n_cmp(s1, s2, 5) ? "not equal" : "equal");

  return (0);
}
