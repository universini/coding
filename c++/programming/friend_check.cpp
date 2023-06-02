#include <iostream>

using namespace std;

class friend_check {
  int a, b;

public:
  friend_check(int x, int y) {
    a = x;
    b = y;
  }

  int sum(void) { return (a + b); }

  void output() { cout << a << " " << b; }

  friend int product(friend_check);
};

int product(friend_check f) {
  f.a = 10;
  f.b = 20;
  return (f.a * f.b);
}

// forward declaration
class ClassB;

class ClassA {

public:
  // constructor to initialize numA to 12
  ClassA() : numA(12) {}

private:
  int numA;

  // friend function declaration
  friend int add(ClassA, ClassB);
};

class ClassB {

public:
  // constructor to initialize numB to 1
  ClassB() : numB(1) {}

private:
  int numB;

  // friend function declaration
  friend int add(ClassA, ClassB);
};

// access members of both classes
int add(ClassA objectA, ClassB objectB) {
  return (objectA.numA + objectB.numB);
}

int main() {
  ClassA objectA;
  ClassB objectB;
  cout << "Sum: " << add(objectA, objectB) << endl;

  friend_check f(2, 3);
  cout << "sum:" << f.sum() << endl;
  cout << "product:" << product(f) << endl;
  f.output();

  return 0;
}