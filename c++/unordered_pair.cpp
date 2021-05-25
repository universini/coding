#include <iostream>
#include <vector>

using namespace std;

void print_unordered(vector<int> v1, vector<int> v2) {
  vector<int>::iterator it1;
  vector<int>::iterator it2;

  for (it1 = v1.begin(); it1 != v1.end(); ++it1)
    for (it2 = v2.begin(); it2 != v2.end(); ++it2)
      if (*it1 < *it2) cout << *it1 << ',' << *it2 << "\n";
}

int main(void) {
  vector<int> v1;
  vector<int> v2;

  v1.push_back(2);
  v1.push_back(1);
  v1.push_back(4);
  v1.push_back(6);
  v1.push_back(3);

  v2.push_back(2);
  v2.push_back(4);
  v2.push_back(5);
  v2.push_back(1);
  v2.push_back(7);

  print_unordered(v1, v2);

  return (0);
}
