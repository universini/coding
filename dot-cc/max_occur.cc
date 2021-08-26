#include <iostream>
#include <string>
#include <map>

using namespace std;

char max_occurance(string s) {
  map<char, int> m;
  int len = s.length();
  int max = 0;
  char ch = ' ';

  for (size_t i = 0; i < len; i++) {
    m[s[i]]++;
    if (max < m[s[i]]) {
      max = i;
      ch = s[i];
    }
  }

  return ch;
}

int main() {
  string s = "siddegowda";
  cout << "max occured char is : " << max_occurance(s) << endl;
  return 0;
}
