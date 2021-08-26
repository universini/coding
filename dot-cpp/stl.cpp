#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <stack>
#include <queue>
#include <map>

using namespace std;

void show_vector(vector<int> v) {
  cout << "show vector:\n";
  vector<int>::iterator it;

  if (v.empty()) {
    return;
  }

  for (it = v.begin(); it != v.end(); ++it) {
    cout << *it << " ";
  }

  cout << endl;
}

void show_list(list<double> l) {
  cout << "show list:\n";
  list<double>::iterator it;

  for (it = l.begin(); it != l.end(); ++it) {
    cout << *it << " ";
  }

  cout << endl;
}

void show_pair(pair<string, int> p) {
  cout << "show pair:\n";
  cout << "[" << p.first << ":" << p.second << "]";
  cout << endl;
}

void show_stack(stack<string> &s) {
  cout << "show stack:\n";
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
}

void show_queue(queue<string> &q) {
  cout << "show queue:\n";
  while (!q.empty()) {
    cout << q.front() << endl;
    q.pop();
  }
}

void show_map(map<string, int> &m) {
  cout << "show map:\n";
  map<string, int>::iterator it;

  for (it = m.begin(); it != m.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}

void show_multimap(multimap<string, int> &mm) {
  cout << "show multimap:\n";
  map<string, int>::iterator it;

  for (it = mm.begin(); it != mm.end(); ++it) {
    cout << it->first << " " << it->second << endl;
  }
}

int main(void) {
  vector<int> v;
  list<double> l;
  pair<string, int> p;
  stack<string> s;
  queue<string> q;
  map<string, int> m;
  multimap<string, int> mm;

  for (int i = 20; i < 60; i += 10) {
    v.push_back(i);
  }

  v.insert(v.begin(), 10);
  v.insert(v.end(), 60);

  show_vector(v);

  for (double d = 10.1; d < 80.1; d += 10) {
    l.push_front(d);
  }

  l.erase(l.begin());

  show_list(l);

  p = make_pair("Sidde", 48);
  show_pair(p);

  s.push("Sidde");
  s.push("Nanditha");
  s.push("Nidarshan");
  s.push("Nivedan");
  show_stack(s);

  q.push("Sidde");
  q.push("Nanditha");
  q.push("Nidarshan");
  q.push("Nivedan");
  show_queue(q);

  m.insert(make_pair("Sidde", 48));
  m.insert(make_pair("Nanditha", 42));
  m.insert(make_pair("Nidarshan", 18));
  m.insert(make_pair("Nivedan", 14));

  show_map(m);

  mm.insert(make_pair("Sidde", 48));
  mm.insert(make_pair("Sidde", 48));
  mm.insert(make_pair("Nidarshan", 18));
  mm.insert(make_pair("Nivedan", 14));

  show_multimap(mm);

  return (0);
}
