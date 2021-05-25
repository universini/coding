#include <stdio.h>
#include <malloc.h>

struct queue {
  struct queue *next;
  int num;
};

typedef struct queue node;

void print_queue(node *f) {
  while (f != NULL) {
    printf("%d->", f->num);
    f = f->next;
  }

  printf("NULL\n");

  return;
}

void pop_queue(node **f) {
  node *t = *f;

  printf("%d\n", t->num);
  *f = (*f)->next;
  free(t);

  return;
}

void add_node(node **f, node **r, int i) {
  node *t;

  t = malloc(sizeof(node));
  t->num = i;
  t->next = NULL;

  if (*f == NULL) {
    *f = t;
  } else {
    (*r)->next = t;
  }

  *r = t;

  return;
}

int main(void) {
  node *f = NULL;
  node *r = NULL;
  int i;

  for (i = 1; i <= 10; i++) {
    add_node(&f, &r, i);
  }

  printf("\nqueue: ");

  print_queue(f);

  printf("\npopped: ");

  pop_queue(&f);

  return (0);
}
