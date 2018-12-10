#include<stdio.h>
#include<string.h>

int chars[26];

char *remove_dup(char s[])
{
    int i=0, j=0;

    while(s[i] != '\0') {
        if (chars[s[i] - 'a'] == 0) {
            chars[s[i] - 'a']++;
            s[j] = s[i];
            j++;
        }

        i++;
    }

    s[j] = '\0';

    return(s);
}

int main (void)
{
    char s[] = "sidde";

    printf("New string: %s\n", remove_dup(s));
    return(0);
}

