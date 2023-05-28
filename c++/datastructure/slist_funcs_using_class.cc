#include <iostream>
#include <queue>

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
    node *temp = *head;

    if (*head == nullptr) {
      *head = get_node(data);
    } else {
      while (temp->next != nullptr) {
        temp = temp->next;
      }
      temp->next = get_node(data);
    }
  }

  void print_list(node *head) {
    node *temp = head;

    if (temp == nullptr) {
      return;
    } else {
      while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
      }
    }
  }

  void delete_node(node **head, int data) {
    node *temp = *head;
    node *prev = nullptr;

    if (*head == nullptr) {
      return;
    } else {
      if ((*head)->data == data) {
        *head = (*head)->next;
        delete temp;
      } else {
        while (temp->next != nullptr && temp->data != data) {
          prev = temp;
          temp = temp->next;
        }

        if (prev != nullptr && temp->data == data) {
          prev->next = temp->next;
          delete temp;
        }
      }
    }
  }

  void delete_all(node **head, int data) {
    node *temp = *head;
    node *prev = nullptr;

    while (*head != nullptr && (*head)->data == data) {
      *head = (*head)->next;
      delete temp;
      temp = *head;
    }

    while (temp->next != nullptr) {
      prev = temp;
      temp = temp->next;

      if (temp->data == data) {
        prev->next = temp->next;
      }
    }
  }

  node *split_list(node *head) {
    node *slow = head;
    node *fast = head;

    while (fast->next->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }

    node *second = slow->next;
    slow->next = nullptr;
    return second;
  }

  node *reverse_list(node *head) {
    node *temp, *rev = NULL;

    while (head != NULL) {
      temp = head->next;
      head->next = rev;
      rev = head;
      head = temp;
    }

    return (rev);
  }
};

int main(void) {
  slist sl;
  node *head = nullptr;

  sl.insert_node(&head, 6);
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
  sl.delete_node(&head, 12);
  cout << " List After Deleting 12 : ";
  sl.print_list(head);
  cout << endl;
  sl.delete_all(&head, 6);
  cout << " List After Deleting All 6s : ";
  sl.print_list(head);
  cout << endl;
  return (0);
}
