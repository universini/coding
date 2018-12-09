#include<stdio.h>
#include<string.h>

int count_chars[256]; // all acsii chars

int non_repeat (const char *str)
{
    for (int i=0; i<strlen(str); i++) {
        count_chars[*(str+i) - 'a']++;
    }

    for (int i=0; i<strlen(str); i++) {
        if (count_chars[*(str+i)-'a'] == 1) {
            return (*(str+i));
        }
    }

    return (0);
}

int main (void)
{
    char *str = "siddesi";

    printf("First non-repeat char: %c\n", non_repeat(str));

    return(0);
}

