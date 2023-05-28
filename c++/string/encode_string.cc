#include <iostream>
#include <string>

using namespace std;

string encode_string_1(const string& str) {
  string result = "";
  int len = str.length();
  int count = 0;
  char ch = ' ';

  for (int i = 0; i < len; i++) {
    if (isalpha(str[i]) && str[i] != ch) {
      ch = str[i];
      count++;
    }

    if (str[i + 1] == ch) {
      count++;
      continue;
    }

    cout << "character: " << ch << " count: " << count << endl;
    result += to_string(count) + ch;
    count = 0;
  }

  return result;
}

string encode_string_2(string str) {
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

int main(void) {
  string str("aaaaaaaaaaaaaaaaaaabbcdddddeffff");
  string res1 = encode_string_1(str);
  cout << "encoded string: " << res1 << endl;
  string res2 = encode_string_2(str);
  cout << "encoded string: " << res2 << endl;
  return 0;
}