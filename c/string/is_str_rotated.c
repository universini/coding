#include <stdio.h>
#include <string.h>

int isRotatedString(const char *s1, const char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 != len2)
        return 0;

    char concat[2 * len1 + 1];
    strcpy(concat, s1);
    strcat(concat, s1);

    return strstr(concat, s2) != NULL;
}

int main() {
    const char *s1 = "waterbottle";
    const char *s2 = "erbottlewat";

    if (isRotatedString(s1, s2)) {
        printf("'%s' is a rotated string of '%s'\n", s2, s1);
    } else {
        printf("'%s' is not a rotated string of '%s'\n", s2, s1);
    }

    return 0;
}
