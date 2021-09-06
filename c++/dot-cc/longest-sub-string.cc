#include <iostream>
#include <map>
#include <string>
#include <vector>

#ifdef SHORT_VERSION
#include <unordered_map>
#endif

using namespace std;

int longestSubstringLen(string s) {
  vector<int> v(256, -1);
  int left = 0;
  int right = 0;  // start left and right index at zero
  int sz = s.size();
  int len = 0;
  while (right < sz) {
    // check if char is repeated or not
    if (v[s[right]] != -1) {
      // jump left to the next index of repeated char
      left = max(v[s[right]] + 1, left);
    }

    // update new location of char
    v[s[right]] = right;
    // check if new length is longer than previous length
    len = max(len, right - left + 1);
    // move right forward
    right++;
  }
  return len;
}

#ifdef SHORT_VERSION
int longestSubstringLen(string s) {
  unordered_map<int, int> cnt;
  int ans = 0;
  int last = -1;
  for (int i = 1; i <= s.length(); i++) {
    last = max(last, cnt[s[i - 1]]);
    ans = max(ans, i - last);
    cnt[s[i - 1]] = i;
  }

  return ans;
}
#endif

int main() {
  string s{"siddegowdanidagatta"};
  cout << "Longest substring length: " << longestSubstringLen(s) << endl;
  return 0;
}
