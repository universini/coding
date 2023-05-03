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

    int num_chars = stol(l);

#ifdef ORDER_OF_NSQUARE
    for (size_t j = 0; j < num_chars; j++) {
      s.push_back(str[i]);
    }
#else
    if (num_chars > 1) {
      string t(num_chars, str[i]);
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
