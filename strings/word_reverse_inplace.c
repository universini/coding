#include <stdio.h>
#include <string.h>

void rev_str_rec(char *s, int start, int end) {
  char ch;

  if (start >= end) return;

  ch = *(s + start);
  *(s + start) = *(s + end);
  *(s + end) = ch;

  rev_str_rec(s, ++start, --end);
}

void rev_words(char s[], int start, int end) {
  int new_start = 0;
  int new_end = 0;

  while (start <= end) {
    if (s[start] == ' ') {
      start++;
      new_start = start;
      continue;
    } else {
      if (s[start + 1] == ' ' || s[start + 1] == '\0') {
        new_end = start;
        rev_str_rec(s, new_start, new_end);
      }

      start++;
    }
  }
}

int main(void) {
  char s[] = "sidde gowda nidagatta";
  int start = 0, end = strlen(s) - 1;

  puts(s);
  rev_str_rec(s, start, end);
  rev_words(s, start, end);
  puts(s);

  return (0);
}
