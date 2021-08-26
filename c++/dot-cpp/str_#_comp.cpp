#include <iostream>
#include <string>

using namespace std;

int str_comp(const char *s1, const char *s2) {
  while (*s1 || *s2) {
    if ((isalpha(*s1) && isalpha(*s2)) || (isdigit(*s1) && isdigit(*s2))) {
      if (*s1 != *s2) return (*s1 - *s2);
    }

    s1++;
    s2++;
  }

  return (0);
}

int main(void) {
  char s1[] = "Sid#e*ow.da";
  char s2[] = "Sid.e#ow*da";

  if (str_comp(s1, s2))
    cout << "String are not equal";
  else
    cout << "String are equal";

  cout << "\n";

  return (0);
}
