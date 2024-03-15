#include <stdio.h>
#include <stdlib.h>

struct list {
  struct list *next;
  int num;
};

typedef struct list node;

void print_list(node *n) {
  while (n != NULL) {
    printf("%d->", n->num);
    n = n->next;
  }

  printf("NULL\n");

  return;
}

int list_len(node *l) {
  int c = 0;

  while (l->next) {
    c++;
    l = l->next;
  }

  return (c);
}

node *search_node(node *n, int i) {
  if (n == NULL) {
    return (n);
  }

  if (n->num == i) {
    return (n);
  } else {
    return (search_node(n->next, i));
  }
}

node *find_merge_point_node(node *n1, node *n2, int ld) {
  for (int i = 0; i < ld; i++) {
    if (!n1) return (NULL);
    n1 = n1->next;
  }

  while (n1 && n2) {
    if (n1 == n2) return (n1);
    n1 = n1->next;
    n2 = n2->next;
  }

  return (NULL);
}

node *find_merge_point(node *n1, node *n2) {
  int l1 = list_len(n1);
  int l2 = list_len(n2);
  int ld;

  if (l1 > l2) {
    ld = l1 - l2;
    return (find_merge_point_node(n1, n2, ld));
  } else {
    ld = l2 - l1;
    return (find_merge_point_node(n2, n1, ld));
  }
}

node *split_half(node *s) {
  node *slow = s;
  node *fast = s;
  node *second;

  while (fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  second = slow->next;
  slow->next = NULL;

  return (second);
}

node *find_middle(node *s) {
  node *slow = s;
  node *fast = s;

  if (s == NULL) return NULL;

#ifdef OPTION_OLD
  while (fast->next->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }
#endif

  while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
  }

  return (slow);
}

int do_list_has_dup_nodes(node *n) {
  node *t1 = n;
  node *t2 = n->next;

  while (t1 && t2 && t2->next) {
    if (t1 == t2) return (1);

    t1 = t1->next;
    t2 = t2->next;
  }

  return (0);
}

// Function to reverse the linked list
node* reverse_list2(node* head) {
    node* prev = NULL;
    node* current = head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;  // Save the next node
        current->next = prev;   // Reverse the link
        prev = current;        // Move one step forward
        current = next;        // Move one step forward
    }

    return prev;  // The new head of the reversed list
}

void reverse_list(node **n) {
  node *r, *s, *q;

  q = *n;
  r = NULL;

  while (q != NULL) {
    s = r;
    r = q;
    q = q->next;
    r->next = s;
  }

  *n = r;

  return;
}

void delete_dup(node **h) {
  node *t = *h;
  node *n;

  if (t == NULL) return;

  while (t->next != NULL) {
    n = t->next;
    if (t->num == n->num) {
      t->next = n->next;
      free(n);
    } else {
      t = t->next;
    }
  }

  return;
}

void delete_node(node **h, int i) {
  node *p, *t = *h;

  if ((*h)->num == i) {
    *h = (*h)->next;
    free(t);
  } else {
    while (t->next != NULL) {
      p = t;
      t = t->next;
      if (t->num == i) {
        p->next = t->next;
        free(t);
      }
    }
  }

  return;
}

void add_node(node **h, int i) {
  node *t = *h;

  if (*h == NULL) {
    *h = malloc(sizeof(node));
    t = *h;
  } else {
    while (t->next != NULL) {
      t = t->next;
    }

    t->next = malloc(sizeof(node));
    t = t->next;
  }

  t->num = i;
  t->next = NULL;

  return;
}

int main(void) {
  node *s, *n = NULL;
  int i;

  add_node(&n, 1); // duplicate entry

  for (i = 1; i <= 14; i++) {
    add_node(&n, i);
  }

  add_node(&n, i-1); // duplicate entry
  add_node(&n, i-1); // duplicate entry
  printf("original linked list: \n");
  print_list(n);

  delete_dup(&n);
  printf("after duplicates are deleted: \n");
  print_list(n);

  delete_node(&n, i-1); // duplicate entry
  printf("after deleting last node: \n");
  print_list(n);

  reverse_list(&n);
  printf("reversed linked list: \n");
  print_list(n);

  s = split_half(n);

  printf("split linked lists: \n");
  print_list(n);
  print_list(s);

  s = find_merge_point(n, s);
  if (s) printf("merge point: %d\n", s->num);

  printf("has dup node: %s\n",
         do_list_has_dup_nodes(n) ? "true" : "false");

  return (0);
}
