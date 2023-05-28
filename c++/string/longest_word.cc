#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubsequence(string s, string t) {
  int i = 0, j = 0;
  while (i < s.length() && j < t.length()) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return i == s.length();
}

string findLongestWord(string s, vector<string>& d) {
  // sort(d.begin(), d.end(), [](const string& a, const string& b) {
  //     if (a.length() == b.length()) {
  //         return a < b;
  //     }
  //     return a.length() > b.length();
  // });
  for (const auto& word : d) {
    if (isSubsequence(word, s)) {
      return word;
    }
  }
  return "";
}

int main() {
  string s = "abpclefk";
  vector<string> d = {"ale", "apple", "monkey", "plea"};

  string longestWord = findLongestWord(s, d);

  cout << "Longest word in dictionary by deleting: " << longestWord << endl;

  return 0;
}
