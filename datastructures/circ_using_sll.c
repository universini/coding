#include <stdio.h>
#include <malloc.h>

#define cq_empty(h) ((h)->next == (h))

struct queue {
  struct queue *next;
  int num;
};

typedef struct queue node;

int is_cqueue(node *f) {
  node *s = f;

  if (!f) {
    return (1);
  }

  while (s && (s != f)) {
    s = s->next;
  }

  return (s == f);
}

void print_queue(node *f) {
  node *t1 = f;
  node *t2 = NULL;

  while (t1 != t2) {
    printf("%d->", t1->num);
    t1 = t1->next;
    t2 = f;
  }

  printf("head\n");

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
  (*r)->next = *f;

  return;
}

int main(void) {
  node *f = NULL;
  node *r = NULL;
  int i;

  for (i = 1; i <= 10; i++) {
    add_node(&f, &r, i);
  }

  printf("queue: ");

  print_queue(f);

  printf("%s\n", is_cqueue(f) ? "circular" : "not a circular");

  return (0);
}
