#include <iostream>
#include <string>

using namespace std;

string encode_string(string str) {
  int len = str.length();
  string s = "";
  long count = 1;
  char ch;

  for (size_t i = 0; i < len; i++) {
    if (str[i] == str[i + 1]) {
      count++;
    } else {
      s += to_string(count);
      s += str[i];
      count = 1;
    }
  }

  return s;
}

int main() {
  string s = "aaabbcdddddeffff";
  cout << "encoded string is : " << encode_string(s) << endl;
  return 0;
}
