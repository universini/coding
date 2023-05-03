#include <iostream>
#include <string>

using namespace std;

string decode_string(string str) {
  int len = str.length();
  string s = "";
  string l = "";

  for (size_t i = 0; i < len; i++) {
    if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
      l.push_back(str[i]);
      continue;
    }

    int repeat_num = stol(l);

#ifdef ORDER_OF_NSQUARE
    for (size_t j = 0; j < repeat_num; j++) {
      s.push_back(str[i]);
    }
#else
    if (repeat_num > 1) {
      string t(repeat_num, str[i]);
      s.insert(s.length(), t);
    } else {
      s += str[i];
    }

    l = "";
#endif
  }

  return s;
}

int main() {
  string s = "19a2b1c5d1e4f";
  cout << "decoded string is : " << decode_string(s) << endl;
  return 0;
}
