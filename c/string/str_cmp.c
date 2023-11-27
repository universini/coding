#include <stdio.h>
#include <string.h>

int str_cmp1(char *s1, char *s2) {
  while (*s1 == *s2)
    if (*s1 == '\0' || *s2 == '\0')
      return (0);
    else {
      s1++;
      s2++;
    }

  return (*s1 - *s2);
}

/*
 * Compare strings:  s1>s2: >0  s1==s2: 0  s1<s2: <0
 */
int str_cmp2(char *s1, char *s2) {
  while (*s1 == *s2++)
    if (*s1++=='\0')
      return(0);
  return(*s1 - *--s2);
}

int main(void) {
  char s[] = "sidde";
  char t[] = "siddego";

  printf("str_cmp1 returned: %s\n",
    str_cmp1(s, t) == 0 ? "pass" : "fail");
  printf("str_cmp2 returned: %s\n",
    str_cmp2(s, t) == 0 ? "pass" : "fail");

  return (0);
}
