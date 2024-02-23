#include <stdio.h>
#include <stdbool.h>

#define MAX_CHARS 256 // ASCII characters

void printCommonChars(const char* str1, const char* str2) {
    int chars[MAX_CHARS] = {0};

    // Count occurrences of characters in str1
    for (int i = 0; str1[i] != '\0'; i++) {
        chars[str1[i]]++;
    }

    // Count occurrences of characters in str2
    for (int i = 0; str2[i] != '\0'; i++) {
        chars[str2[i]]++;
    }

    // Print common characters
    for (int i = 0; str1[i] != '\0'; i++) {
        // printf("chars count: %c [%d]\n", str1[i], chars[str1[i]]);
        if (chars[str1[i]] > 1) {
            printf("%c ", str1[i]);
            chars[str1[i]] = 0; // Mark as printed to avoid duplicates
        }
    }
    printf("\n");
}

int main() {
    const char* str1 = "hello";
    const char* str2 = "world";
    printf("Common characters: ");
    printCommonChars(str1, str2);
    return 0;
}
