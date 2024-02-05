#include <iostream>
#include <unordered_set>
#include <algorithm>

int lengthOfLongestSubstring(const std::string& s) {
    int n = s.length();
    int maxLength = 0;
    int i = 0, j = 0;
    std::unordered_set<char> charSet;

    while (j < n) {
        if (charSet.find(s[j]) == charSet.end()) {
            charSet.insert(s[j]);
            maxLength = std::max(maxLength, j - i + 1);
            j++;
        } else {
            charSet.erase(s[i]);
            i++;
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    std::string input = "abcabcbb";
    int result = lengthOfLongestSubstring(input);

    std::cout << "Longest substring without repeating characters: " << result << std::endl;

    return 0;
}
