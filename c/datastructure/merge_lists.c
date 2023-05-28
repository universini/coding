#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
  struct node_s *next;
  int data;
} node_t;

void print_list(node_t *n) {
  node_t *t = n;

  while (t != NULL) {
    printf("%d ", t->data);
    t = t->next;
  }
}

node_t *getnode(int n) {
  node_t *t;

  t = malloc(sizeof(node_t));
  t->data = n;
  t->next = NULL;

  return (t);
}

node_t *reverse(node_t *n) {
  node_t *t;
  node_t *r = NULL;

  while (n != NULL) {
    t = n->next;
    n->next = r;
    r = n;
    n = t;
  }

  return (r);
}

node_t *merge_lists(node_t *n1, node_t *n2) {
  if (!n1 && !n2) return (NULL);
  if (!n1) return (n2);
  if (!n2) return (n1);

  if (n1->data < n2->data) {
    n1->next = merge_lists(n1->next, n2);
    return (n1);
  } else {
    n2->next = merge_lists(n1, n2->next);
    return (n2);
  }
}

int main(void) {
  node_t *n3 = NULL;
  node_t *n1 = getnode(3);
  node_t *n2 = getnode(7);
  n1->next = getnode(4);
  n1->next->next = getnode(5);
  n1->next->next->next = getnode(6);
  n2->next = getnode(8);
  n2->next->next = getnode(9);

  print_list(n1);
  printf("\n");
  print_list(n2);
  printf("\n");

  n3 = merge_lists(n1, n2);
  print_list(n3);
  printf("\n");

  print_list(reverse(n3));
  printf("\n");

  return (0);
}
