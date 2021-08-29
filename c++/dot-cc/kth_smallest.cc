#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kth_smallest(vector<int> v, int kth) {
  // construct a max hep from vector elements
  priority_queue<int> p(v.begin(), v.begin() + kth);

  for (size_t i = kth; i < v.size(); i++) {
    if (p.top() > v[i]) {
      p.pop();
      p.push(v[i]);
    }
  }
  return p.top();
}

int main(void) {
  vector<int> v{2, 4, 1, 3, 9, 5, 0};
  int k;

  cout << "Enter kth number : ";
  cin >> k;
  cout << "kth smallest element is : " << kth_smallest(v, k) << endl;

  return 0;
}
