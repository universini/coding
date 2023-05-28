#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
    The function lengthOfLongestSubstring takes a string s as input and returns
    the length of the longest substring without repeating characters. The
    algorithm maintains two pointers i and j that represent the left and right
    endpoints of the current substring. The algorithm also maintains an unordered
    set seen that keeps track of the characters that have been seen in the
    current substring. Initially, both i and j are at the beginning of the
    string and seen is empty. The algorithm then iterates over the string s
    from left to right. If the character s[j] is not in the set seen, the
    algorithm adds it to the set, moves j one position to the right, and updates
    the maximum length of the substring. If the character s[j] is already in the
    set seen, the algorithm removes the character s[i] from the set, moves i one
    position to the right, and continues iterating. The algorithm terminates when
    j reaches the end of the string s. The time complexity of this algorithm is
    O(n), where n is the length of the input string.
*/
int lengthOfLongestSubstring(string s) {
  int n = s.length();
  int maxLength = 0;
  unordered_set<char> seen;
  int i = 0, j = 0;
  while (i < n && j < n) {
    if (seen.find(s[j]) == seen.end()) {
      seen.insert(s[j]);
      j++;
      maxLength = max(maxLength, j - i);
    } else {
      seen.erase(s[i]);
      i++;
    }
  }
  return maxLength;
}

int main() {
  string s = "abcabcbb";
  int length = lengthOfLongestSubstring(s);
  cout << "Length of longest substring without repeating characters: " << length << endl;
  return 0;
}
