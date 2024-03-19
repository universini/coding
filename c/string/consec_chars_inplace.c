#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cons_chars(char *s)
{
    if (s == NULL || *s == '\0') {
        return;
    }

    char j = s[0];
    int count = 1;
    size_t k = 0;
    char cnt[32];

    for (size_t i = 1; s[i] != '\0'; ++i) {
        if (s[i] == j) {
            count++;
        } else {
            if (count > 1) {
                s[k++] = j;
                sprintf(cnt, "%d", count);
                strcpy(s + k++, cnt);
                count = 1;
            }
            else
            {
                s[k++] = j;
            }

            j = s[i];
        }
    }

    if (count > 1) {
        s[k++] = j;
        sprintf(cnt, "%d", count);
        strcpy(s + k++, cnt);
    }

    s[k] = '\0';
}

int main() {
    char s[] = "aaabcdee";
    printf("Input: %s\n", s);
    cons_chars(s);
    printf("Output: %s\n", s);
    return 0;
}
