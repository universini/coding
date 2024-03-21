#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* cons_chars(const char *s) {
  unsigned long count;
  unsigned long i, j = 1, k = 0;
  char *t;

  count = 1;

  t = (char *)malloc(strlen(s) * sizeof(char));

  for (i = 0; i < strlen(s); i++) {
    if (*(s + i) == *(s + j)) {
      count++;
    } else {
      char cnt[32];
      sprintf(cnt, "%lu", count);
      *(t + k++) = *(s + i);
      strcpy((t + k++), cnt);
      count = 1;
    }
    j++;
  }

  t[k] = '\0';

  return (t);
}

char* cons_chars_greater_than_one(const char *s) {
  unsigned long count;
  unsigned long i, j = 1, k = 0;
  char *t;

  count = 1;

  t = (char *)malloc(strlen(s) * sizeof(char));

  for (i = 0; i < strlen(s); i++) {
    if (*(s + i) == *(s + j)) {
      count++;
    } else {
      if (count > 1) {
        char cnt[32];
        sprintf(cnt, "%lu", count);
        *(t + k++) = *(s + i);
        strcpy((t + k++), cnt);
        count = 1;
      } else {
        *(t + k++) = *(s + i);
      }
    }
    j++;
  }

  t[k] = '\0';

  return (t);
}

int main(void) {
  char s[] = "aaabcdee";
  char *t;

  t = cons_chars(s);
  printf("solution1: %s\n", t);

  t = cons_chars_greater_than_one(s);
  printf("solution2: %s\n", t);

  free(t);

  return (0);
}
