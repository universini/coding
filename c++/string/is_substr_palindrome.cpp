#include <iostream>
#include <string>

bool isPalindrome(const std::string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

bool hasPalindromeSubstring(const std::string& str) {
    int n = str.length();
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (isPalindrome(str, i, j)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::string s = "abaxyzzyxf";

    if (hasPalindromeSubstring(s)) {
        std::cout << "Yes, the string contains a palindrome substring." << std::endl;
    } else {
        std::cout << "No, the string does not contain a palindrome substring." << std::endl;
    }

    return 0;
}
