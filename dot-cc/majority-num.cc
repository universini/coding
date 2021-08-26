#include <iostream>
#include <map>
#include <vector>

std::map<int, int> m;

int majorityElement(std::vector<int>& v, int s) {
  for (size_t i = 0; i < s; i++) {
    m[v[i]]++;
  }

  for (auto x : m) {
    if (x.second > s / 2) return x.first;
  }

  return 0;
}

int main(void) {
  std::vector<int> v{2, 1, 2};
  std::cout << "Majority Element: " << majorityElement(v, v.size())
            << std::endl;
  return (0);
}
