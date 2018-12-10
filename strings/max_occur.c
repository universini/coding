#include<stdio.h>
#include<string.h>

int char_hash[26];

int max_occur (char *s, int l)
{
    int max = 0;

    for (int i=0; i<=l; i++) {
        char_hash[*(s+i)]++;
        if (max < char_hash[*(s+i)]) {
            max = char_hash[*(s+i)];
        }
    }

    return(max);
}

int main (void)
{
    char s[]="siddeees";
    int l = strlen(s)-1;

    printf("imax occur: %d\n", max_occur(s, l));
    return(0);
}

