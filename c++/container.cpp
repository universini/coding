#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class container {
  stack<vector<int> > s;

 public:
  void insert(vector<int>& v) { s.push(v); }

  void remove(void) {
    vector<int> v;
    vector<int>::iterator it;

    while (!s.empty()) {
      v = s.top();
      for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
      s.pop();
      v.clear();
    }
  }
};

int main(void) {
  vector<int> in;
  vector<int> v;
  vector<int>::iterator it;
  container c;
  int sum = 0;

  in.push_back(30);
  in.push_back(5);
  in.push_back(6);
  in.push_back(26);
  in.push_back(7);
  in.push_back(16);
  in.push_back(6);
  in.push_back(9);
  in.push_back(4);

  for (it = in.begin(); it != in.end(); ++it) {
    sum += *it;
    if (sum <= 40) {
      v.push_back(*it);
    } else {
      vector<int> vt;
      c.insert(v);
      v = vt;
      sum = *it;
      v.push_back(sum);
    }
  }

  c.insert(v);

  c.remove();

  return (0);
}
