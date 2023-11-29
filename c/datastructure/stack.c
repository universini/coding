#include <stdio.h>
#include <stdlib.h>

struct stack {
  struct stack *next;
  int num;
};

typedef struct stack node;

void print_stack(node *f) {
  while (f != NULL) {
    printf("%d->", f->num);
    f = f->next;
  }

  printf("NULL\n");

  return;
}

void pop_stack(node **n) {
  node *t = *n;

  printf("%d\n", t->num);
  *n = (*n)->next;
  free(t);

  return;
}

void add_node(node **n, int i) {
  node *t;

  t = malloc(sizeof(node));
  t->num = i;
  t->next = NULL;

  t->next = *n;
  *n = t;

  return;
}

int main(void) {
  node *n = NULL;
  int i;

  for (i = 1; i <= 10; i++) {
    add_node(&n, i);
  }

  printf("\nstack: ");

  print_stack(n);

  printf("\npopped: ");

  pop_stack(&n);

  return (0);
}
