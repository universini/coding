#include <stdio.h>
#include <string.h>

#define false 0
#define true 1

int count_chars[26];

int find_anagrams(const char *str1, const char *str2)
{
  if (strlen(str1) != strlen(str2))
    return false;

  for (int i = 0; i < strlen(str1); i++)
    count_chars[*(str1 + i) - 'a']++;

  for (int i = 0; i < strlen(str2); i++)
  {
    if (!count_chars[*(str2 + i) - 'a'])
      return false;
    count_chars[*(str2 + i) - 'a']--;
  }

  return true;
}

int main(void)
{
  char *s1 = "sidde";
  char *s2 = "dised";

  printf("Given strings are %s\n",
         find_anagrams(s1, s2) ? "anagrams" : "not anagrams");

  return 0;
}
