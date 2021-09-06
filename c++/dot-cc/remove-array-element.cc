#include <iostream>
#include <vector>

using namespace std;

void remove(vector<int>& v, int k) {
  int len = v.size();

  for (int i = 0; i < len; i++) {
    if (v[i] == k) {
      v.erase(v.begin() + i);
      break;
    }
  }

  return;
}

void remove_2(int a[], int size, int k) {
  int idx;
  // remove 30
  for (idx = 0; idx < size; idx++) {
    if (a[idx] == k) break;
  }

  for (int i = idx; i < size; i++) {
    a[i] = a[i + 1];
  }
}

int main() {
  int a[] = {10, 20, 30, 40};
  int size = sizeof(a) / sizeof(a[0]);

  remove_2(a, size, 30);

  cout << "Array after 30 was removed : ";
  for (int i = 0; i < size - 1; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
  remove(v, 5);

  cout << "Array after 5 was removed : ";
  for (auto x : v) cout << x << " ";
  cout << endl;

  return 0;
}
