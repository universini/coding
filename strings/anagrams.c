#include<stdio.h>
#include<string.h>

#define false 0
#define true  1

int count_chars[26];

int find_anagrams (const char *str1, const char *str2)
{
    if (strlen(str1) != strlen(str2)) {
        return (false);
    }

    for (int i=0; i<strlen(str1); i++) {
        count_chars[*(str1+i) - 'a']++;
    }

    for (int i=0; i<strlen(str2); i++) {
        /*
         * if one of strs chars isn't there in str1, return false
         */
        if (!count_chars[*(str2+i)-'a']) {
            return (false);
        }
        count_chars[*(str2+i) - 'a']--;
    }

    return (true);
}

int main (void)
{
    char *str1 = "sidde";
    char *str2 = "dised";

    printf("Given strings are %s\n",
        find_anagrams(str1, str2) ? "anagrams" : "not anagrams");

    return(0);
}

