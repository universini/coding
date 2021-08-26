#include <iostream>

using namespace std;

class list_node {
 public:
  int data;
  list_node *next;
};

void print(list_node *head) {
  list_node *t = head;

  while (t != NULL) {
    cout << t->data << " ";
    t = t->next;
  }

  cout << endl;
}

void remove(list_node **head, int n) {
  list_node *t = *head;

  if (t == NULL) {
    return;
  }

  if (t->data == n) {
    *head = (*head)->next;
    delete (t);
  } else {
    list_node *prev;
    while (t && t->data != n) {
      prev = t;
      t = t->next;
    }

    prev->next = t->next;
    delete (t);
  }
}

list_node *split(list_node *head) {
  list_node *slow = head;
  list_node *fast = head;

  while (fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  list_node *list2 = slow->next;
  slow->next = NULL;

  return (list2);
}

void mystack(list_node **head, int n) {
  list_node *t = new list_node();

  t->data = n;
  t->next = NULL;

  if (*head == NULL) {
    *head = t;
  } else {
    t->next = *head;
    *head = t;
  }
}

void myqueue(list_node **head, list_node **rear, int n) {
  list_node *t = new list_node();

  t->data = n;
  t->next = NULL;

  if (*head == NULL) {
    *head = t;
  } else {
    (*rear)->next = t;
  }

  *rear = t;
}

void insert(list_node **head, int n) {
  if (*head == NULL) {
    *head = new list_node();
    (*head)->data = n;
    (*head)->next = NULL;
  } else {
    list_node *t = *head;

    while (t->next != NULL) t = t->next;

    t->next = new list_node();
    t->next->data = n;
    t->next->next = NULL;
  }
}

int main(void) {
  list_node *list1 = NULL;
  list_node *list2;
  list_node *front = NULL;
  list_node *rear = NULL;
  list_node *head = NULL;

  for (int i = 10; i <= 100; i += 10) {
    insert(&list1, i);
  }

  print(list1);
  list2 = split(list1);
  print(list1);
  print(list2);

  remove(&list1, 30);
  print(list1);
  remove(&list2, 70);
  print(list2);

  for (int i = 2; i <= 10; i += 2) {
    myqueue(&front, &rear, i);
  }

  print(front);

  for (int i = 2; i <= 10; i += 2) {
    mystack(&head, i);
  }

  print(head);

  return (0);
}
