#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Class template
template <class T> class Number {
private:
  // Variable of type T
  T num;

public:
  Number(T n) : num(n) {} // constructor

  T getNum() { return num; }

  void multiplyNum();
};

template <class T> void Number<T>::multiplyNum(void) {
  cout << num * num << endl;
}

template <typename T> T add(T num1, T num2) { return (num1 + num2); }

template <typename T1, typename T2> void print(T1 q, T2 s) {
  cout << q.front() << endl;
  cout << s.top() << endl;
}

// Class template with multiple and default parameters
template <class T, class U, class V = char> class ClassTemplate {
private:
  T var1;
  U var2;
  V var3;

public:
  ClassTemplate(T v1, U v2, V v3) : var1(v1), var2(v2), var3(v3) {}

  void printVar() {
    cout << "var1 = " << var1 << endl;
    cout << "var2 = " << var2 << endl;
    cout << "var3 = " << var3 << endl;
  }
};

int main() {

  // create object with int type
  Number<int> numberInt(7);

  // create object with double type
  Number<double> numberDouble(7.7);

  cout << "int Number = " << numberInt.getNum() << endl;
  cout << "double Number = " << numberDouble.getNum() << endl;

  numberInt.multiplyNum();

  queue<int> q;
  stack<string> s;

  int result1;
  double result2;
  // calling with int parameters
  result1 = add<int>(2, 3);
  cout << "2 + 3 = " << result1 << endl;

  // calling with double parameters
  result2 = add<double>(2.2, 3.3);
  cout << "2.2 + 3.3 = " << result2 << endl;

  for (int i = 10; i < 50; ++i)
    q.push(i);
  s.push("sidde");
  s.push("gowda");
  print<queue<int>, stack<string>>(q, s);

  ClassTemplate<int, double> obj1(7, 7.7, 'c');
  cout << "obj1 values: " << endl;
  obj1.printVar();

  ClassTemplate<int, double, string> obj2(7, 7.7, "sidde");
  cout << "obj2 values: " << endl;
  obj2.printVar();

  return 0;
}