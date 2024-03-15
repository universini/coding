#include <stdio.h>
#include <string.h>

// Function to check if a substring is palindrome
int isPalindrome(char* str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return 0; // Not a palindrome
        }
        start++;
        end--;
    }
    return 1; // Palindrome
}

// Function to count palindromic substrings in a string
int countPalindromes(char* str) {
    int n = strlen(str);
    int count = 0;

    // Create a table to store whether substrings are palindromes
    int dp[n][n];
    memset(dp, 0, sizeof(dp));

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        count++;
    }

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = 1;
            count++;
        }
    }

    // Check substrings of length greater than 2
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = 1;
                count++;
            }
        }
    }

    return count;
}

int main() {
    char str[] = "abaaa";
    int result = countPalindromes(str);
    printf("Number of palindromic substrings: %d\n", result);
    return 0;
}
