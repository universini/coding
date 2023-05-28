#include <stdio.h>
#include <string.h>

void word_reverse(char s[]) {
  int l = strlen(s);

  while (l--) {
    if (*(s + l) == ' ') {
      *(s + l) = '\0';
      printf("%s ", &(*(s + l + 1)));
    }
  }

  printf("%s\n", s);

  return;
}

int main(void) {
  char s[] = "sidde gowda nidagatta";

  word_reverse(s);

  return (0);
}
