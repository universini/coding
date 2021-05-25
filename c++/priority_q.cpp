#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue<int> gq) {
  priority_queue<int> g = gq;
  while (!g.empty()) {
    cout << '\t' << g.top();
    g.pop();
  }
  cout << '\n';
}

int main() {
  priority_queue<int> gquiz;
  gquiz.push(10);
  gquiz.push(30);
  gquiz.push(20);
  gquiz.push(5);
  gquiz.push(1);

  cout << "The priority queue gquiz is : ";
  showpq(gquiz);

  cout << "\ngquiz.size() : " << gquiz.size();
  cout << "\ngquiz.top() : " << gquiz.top();

  cout << "\ngquiz.pop() : ";
  gquiz.pop();
  showpq(gquiz);

  return 0;
}

/*
#include <iostream>
#include <queue>

using namespace std;

void showpq(priority_queue <int, vector<int>, greater<int>> gq)
{
    priority_queue <int, vector<int>, greater<int>> g = gq;
    while (!g.empty())
    {
        cout << '\t' << g.top();
        g.pop();
    }
    cout << '\n';
}

int main ()
{
    priority_queue <int, vector<int>, greater<int>> gquiz;
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    gquiz.push(5);
    gquiz.push(1);

    cout << "The priority queue gquiz is : ";
    showpq(gquiz);

    cout << "\ngquiz.size() : " << gquiz.size();
    cout << "\ngquiz.top() : " << gquiz.top();


    cout << "\ngquiz.pop() : ";
    gquiz.pop();
    showpq(gquiz);

    return 0;
}
*/
/*
#include <queue>
#include <iostream>

using namespace std;

struct comparator {
 bool operator()(int i, int j) {
 return i > j;
 }
};

int main(int argc, char const *argv[])
{
 priority_queue<int, std::vector<int>, comparator> minHeap;

 minHeap.push(10);
 minHeap.push(5);
 minHeap.push(12);
 minHeap.push(3);
 minHeap.push(3);
 minHeap.push(4);

 while (!minHeap.empty()) {
 cout << minHeap.top() << " ";
 minHeap.pop();
 }
 return 0;
}
*/
