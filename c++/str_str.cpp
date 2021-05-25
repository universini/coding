#include <iostream>

int str_len(char *s) {
  char *t = s;

  while (*t) t++;
  return (t - s);
}

int str_ncasecmp(char *s1, char *s2, int l) {
  while (l--) {
    if (*s1 != *s2) return (-1);
    s1++;
    s2++;
  }

  return (0);
}

char *str_str(char *s1, char *s2) {
  int l = str_len(s2);

  while (s1++) {
    if (str_ncasecmp(s1, s2, l) == 0) return (s1);
  }

  return (nullptr);
}

int main(void) {
  char *s = "sidde gowda nidagatta";
  std::cout << str_len(s) << std::endl;
  std::cout << str_str(s, "gowda");
  return (0);
}
