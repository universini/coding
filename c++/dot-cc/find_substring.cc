#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

bool find_matching_substring(string s1[], string s2[], int len1, int len2) {
  unordered_map<string, int> map;

  for (int idx = 0; idx < len1; idx++) {
    map[s1[idx]]++;
  }

  for (int idx = 0; idx < len2; idx++) {
    if (map[s2[idx]]) {
      map[s2[idx]]--;
    } else {
      return false;
    }
  }
  return true;
}

int main(void) {
  string s1[] = {"sidde", "gowda", "nidagatta", "malavalli", "mandya"};
  string s2[] = {"sidde", "gowda", "mandya"};
  int len1 = sizeof(s1) / sizeof(s1[0]);
  int len2 = sizeof(s2) / sizeof(s2[0]);

  cout << "Substring was "
       << (find_matching_substring(s1, s2, len1, len2) ? "found" : "not found")
       << endl;

  return (0);
}
