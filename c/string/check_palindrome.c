#include <stdio.h>
#include <string.h>

void pali_check_1(char s[]) {
  int i, j = strlen(s) - 1;
  int flag = 0;

  for (i = 0; i < j; i++, j--) {
    if (s[i] != s[j]) {
      flag = 1;
      break;
    }
  }

  if (flag) {
    printf("not a palindrome\n");
  } else {
    printf("palindrome\n");
  }

  return;
}

int pali_check_2(char s[]) {
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
  char s[] = "malayalam";

  printf("Given string %s is ", s);
  pali_check_1(s);
  printf("Given string %s is %s\n", s,
         pali_check_2(s) ? "palindrome" : "not a palindrome");

  return (0);
}
