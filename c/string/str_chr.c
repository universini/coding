#include <stdio.h>
#include <string.h>

char *str_chr(char *sp, char c) {
  do {
    if(*sp == c)
      return(sp);
  } while(*sp++);

  return(NULL);
}

int main(void) {
  char *s = "sidde";
  char c = 'e';

  printf("Char in string: %s\n", str_chr(s, c));

  return (0);
}
