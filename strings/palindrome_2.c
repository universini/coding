#include <stdio.h>
#include <string.h>

int pali_check(char s[]) {
  int i, j = strlen(s) - 1;
  int flag = 0;

  for (i = 0; i < j; i++, j--) {
    if (s[i] == s[j]) {
      continue;
    } else {
      return (0);
    }
  }

  return (1);
}

int main(void) {
  char s[] = "marayalam";

  printf("Given string %s %s a palindrome\n", s,
         pali_check(s) ? "is" : "isn't");

  return (0);
}
