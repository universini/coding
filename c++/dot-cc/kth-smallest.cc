#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int kth_smallest(vector<int> v, int kth) {
  // construct a max hep from vector elements
  priority_queue<int> p(v.begin(), v.begin() + kth);

  for (size_t i = kth; i < v.size(); i++) {
    cout << "queue item: " << p.top() << " vector item: " << v[i] << endl;
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
  int kth;

  cout << "Enter kth number : ";
  cin >> k;
  kth = kth_smallest(v, k);
  cout << "kth smallest element is : " << kth << endl;

  return 0;
}
