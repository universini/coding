#include <iostream>
#include <string>

using namespace std;

class str_check {
  string str;

 public:
  str_check(string &s) { str = s; }

  void palindrome(void) {
    int start = 0, end = str.size() - 1;

    while (start < end) {
      if (str[start] != str[end]) {
        cout << "Not a palindrome" << endl;
        return;
      }

      start++;
      end--;
    }
    cout << "Palindrome" << endl;
  }
  // public ends
};

int main(void) {
  string s = "MALAYALAM";
  str_check sc(s);
  sc.palindrome();
  return (0);
}
