#include <iostream>
#include <stack>

using namespace std;

class min_stack {
  stack<int> sta;
  stack<int> min;

 public:
  void push_stack(int num) {
    sta.push(num);

    if (min.empty()) {
      min.push(num);
    } else if (num < min.top()) {
      min.push(num);
    }
  }

  int pop_stack(void) {
    int num = sta.top();
    sta.pop();
    return (num);
  }

  int pop_min(void) {
    int num = min.top();
    min.pop();
    return (num);
  }
};

int main(void) {
  min_stack s;

  s.push_stack(10);
  s.push_stack(2);
  s.push_stack(12);
  s.push_stack(9);
  s.push_stack(6);
  s.push_stack(22);

  cout << "Top: " << s.pop_stack();
  cout << "\n";
  cout << "Min: " << s.pop_min();
  cout << "\n";

  return (0);
}
