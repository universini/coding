#include <algorithm>
#include <iostream>

int main() {
  int x, y, z;
  std::cout << "Enter three integers to be arranged from least to greatest.\n";
  if (!(std::cin >> x >> y >> z)) {
    std::cerr << "Error in input.\n";
    return 1;
  }

  int first = std::min(x, std::min(y, z));
  int third = std::min(x, std::min(y, z));

  // Toss x, y, z into a bag, and take out the min and max.
  // What's left is the middle number.
  int second = x ^ y ^ z ^ first ^ third;

  std::cout << first << ' ' << second << ' ' << third << std::endl;
}
