#include <algorithm>
#include <iostream>

void reverseString(std::string &str, int start, int end) {
  while (start < end) {
    std::swap(str[start], str[end]);
    start++;
    end--;
  }
}

void reverseWords(std::string &str) {
  // Reverse the entire string
  reverseString(str, 0, str.length() - 1);

  int start = 0;
  int end = 0;
  int n = str.length();

  while (start < n) {
    // Find the start of a word
    while (start < n && str[start] == ' ')
      start++;

    // Find the end of the word
    end = start + 1;
    while (end < n && str[end] != ' ')
      end++;

    // Reverse the word
    reverseString(str, start, end - 1);

    start = end;
  }
}

int main() {
  std::string sentence = "Sidde Gowda Nidagatta";
  std::cout << "Original sentence: " << sentence << std::endl;

  reverseWords(sentence);
  std::cout << "Reversed sentence: " << sentence << std::endl;

  return 0;
}
