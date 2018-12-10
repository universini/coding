#include<stdio.h>
#include<string.h>

void pali_check (char s[])
{
    int i, j=strlen(s)-1;
    int flag = 0;

    for (i=0; j>i; i++, j--) {
        if (s[i] != s[j]) {
            flag = 1;
            break;
        }
    }

    if (!flag) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return;
}

int main(void)
{
    char s[] = "malayalam";

    pali_check(s);

    return(0);
}
