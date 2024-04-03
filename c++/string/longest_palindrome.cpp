#include <iostream>
#include <string>

using namespace std;

string expandAroundCenter(const string& s, int left, int right) {
    int n = s.length();
    while (left >= 0 && right < n && s[left] == s[right]) {
        left--;
        right++;
    }
    // Return the palindrome substring centered at left+1 and right-1
    return s.substr(left + 1, right - left - 1);
}

string longestPalindrome(const string& s) {
    int n = s.length();
    if (n == 0) return "";

    string longest = "";
    for (int i = 0; i < n; ++i) {
        // Find the longest palindrome centered at character i
        // For odd-length palindromes
        string palindrome1 = expandAroundCenter(s, i, i);
        // For even-length palindromes
        string palindrome2 = expandAroundCenter(s, i, i + 1);
        // Update the longest palindrome found so far
        if (palindrome1.length() > longest.length()) {
            longest = palindrome1;
        }
        if (palindrome2.length() > longest.length()) {
            longest = palindrome2;
        }
    }
    return longest;
}

int main() {
    string input = "babad";
    string result = longestPalindrome(input);
    cout << "Longest palindrome: " << result << endl;
    return 0;
}
