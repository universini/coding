#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Class template
template <class T>
class Number {
   private:
    // Variable of type T
    T num;

   public:
    Number(T n) : num(n) {}   // constructor

    T getNum() {
        return num;
    }
};

template <typename T>
T add(T num1, T num2) {
    return (num1 + num2);
}

template <typename T1, typename T2>
void print(T1 q, T2 s)
{
    cout << q.front() << endl;
    cout << s.top() << endl;
}

int main() {

    // create object with int type
    Number<int> numberInt(7);

    // create object with double type
    Number<double> numberDouble(7.7);

    cout << "int Number = " << numberInt.getNum() << endl;
    cout << "double Number = " << numberDouble.getNum() << endl;

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

    for (int i=10; i<50; ++i) q.push(i);
    s.push("sidde");
    s.push("gowda");
    print<queue<int>, stack<string>>(q, s);

    return 0;
}