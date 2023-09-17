#include <iostream>
#include <string>
#include <vector>

std::string longestPalindrome(const std::string& s) {
    if (s.empty()) return "";

    // Preprocess the string to handle even-length palindromes
    std::string processed = "#";
    for (char c : s) {
        processed += c;
        processed += "#";
    }

    int n = processed.length();
    std::vector<int> P(n, 0); // Array to store palindrome lengths

    int center = 0;  // Center of the rightmost palindrome
    int right = 0;   // Right boundary of the rightmost palindrome

    for (int i = 0; i < n; ++i) {
        int mirror = 2 * center - i;  // Mirror of i around center

        // Check if i is within the right boundary of the rightmost palindrome
        if (i < right)
            P[i] = std::min(right - i, P[mirror]);

        // Attempt to expand palindrome centered at i
        int a = i + (1 + P[i]);
        int b = i - (1 + P[i]);
        while (a < n && b >= 0 && processed[a] == processed[b]) {
            P[i]++;
            a++;
            b--;
        }

        // If palindrome centered at i expands past right, adjust center and right
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }

    int maxLen = 0;
    int centerIndex = 0;

    for (int i = 0; i < n; ++i) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    // Extract the longest palindrome
    int start = (centerIndex - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    std::string input = "babad";
    std::string longest_palindrome = longestPalindrome(input);

    std::cout << "Longest palindromic substring: " << longest_palindrome << std::endl;

    return 0;
}
