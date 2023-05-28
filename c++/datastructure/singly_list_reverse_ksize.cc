#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct node {
  node *next;
  int data;
};

class slist {
 public:
  slist() = default;
  ~slist() = default;

  node *get_node(int data) {
    node *n = new (node);
    if (!n) return nullptr;
    n->next = nullptr;
    n->data = data;
    return n;
  }

  void insert_node(node **head, int data) {
    node *curr = *head;

    if (*head == nullptr) {
      *head = get_node(data);
    } else {
      while (curr->next != nullptr) {
        curr = curr->next;
      }
      curr->next = get_node(data);
    }
  }

  void print_list(node *head) {
    node *curr = head;

    if (curr == nullptr) {
      return;
    } else {
      while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
      }
    }
  }

  node *reverse_list(node *head, int k) {
    node *curr = head, *prev = nullptr, *next;

    while (curr != nullptr && k) {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
      k--;
    }

    return prev;
  }

  node *rev_k_size(node *head, int k) {
    node *curr = head;
    node *next = nullptr;
    node *prev = nullptr;
    int count = 0;

    if (k == 1) return head;

    while (curr != nullptr && count < k) {
      curr = curr->next;
      count++;
    }

    if (count < k) {
      return head;
    }

    next = curr;
    node *new_head = reverse_list(head, k);
    head->next = rev_k_size(next, k);

    return new_head;
  }
};

int main(void) {
  node *head = nullptr;
  node *prev = nullptr;
  slist sl;

  sl.insert_node(&head, 1);
  sl.insert_node(&head, 6);
  sl.insert_node(&head, 4);
  sl.insert_node(&head, 8);
  sl.insert_node(&head, 6);
  sl.insert_node(&head, 12);
  sl.insert_node(&head, 18);
  sl.insert_node(&head, 9);
  sl.insert_node(&head, 23);
  sl.insert_node(&head, 54);
  sl.insert_node(&head, 81);

  cout << "Singly Linked List : ";
  sl.print_list(head);
  cout << endl;
  prev = sl.rev_k_size(head, 3);
  cout << "Reverded K Size Singly Linked List : ";
  sl.print_list(prev);
  cout << endl;
  return (0);
}
