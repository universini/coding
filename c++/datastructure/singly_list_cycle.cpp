#include <iostream>
#include <unordered_set>

using namespace std;

struct Node {
  int data;
  Node* next;
};

void push(Node*& headRef, int data) {
  Node* newNode = new Node;
  newNode->data = data;
  newNode->next = headRef;
  headRef = newNode;
}

bool detectCycle(Node* head) {
  Node* curr = head;
  unordered_set<Node*> set;

  while (curr) {
    // return false if seen this node before
    if (set.find(curr) != set.end())
      return true;

    // insert current node into the set
    set.insert(curr);
    // move to the next node
    curr = curr->next;
  }

  return false;
}

int main() {
  int keys[] = {1, 2, 3, 4, 5};
  int n = sizeof(keys) / sizeof(keys[0]);

  Node* head = nullptr;
  for (int i = n - 1; i >= 0; i--)
  {
    push(head, keys[i]);
  }

  // insert cycle
  head->next->next->next->next->next = head->next->next;

  if (detectCycle(head))
    cout << "Cycle found\n";
  else
    cout << "No cycle found\n";

  return 0;
}
