#include <stdio.h>
#include <string.h>

void str_cpy(char *t, const char *s) {
  while (*t++ = *s++)
    ;
  return;
}

char *str_cat(char *dst, const char *src) {
  char *dest = dst;

  while (*dst) dst++;

  while (*dst++ = *src++)
    ;

  return (dest);
}

int main(void) {
  char s1[] = "sidde";
  char s2[] = "gowda";
  char s3[32];

  str_cpy(s3, s1);
  printf("Final string: %s\n", str_cat(s3, s2));

  return (0);
}
