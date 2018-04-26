#include <stdio.h>
#include <malloc.h>

#define cq_empty(h) ((h)->next==(h))

struct queue {
    struct queue *next;
    int          num;

};

typedef struct queue node;

void print_queue (node *f)
{
    node *t1 = f;
    node *t2 = NULL;

    while (t1 != t2) {
        printf ("%d->", t1->num);
        t1 = t1->next;
        t2 = f;
    }

    printf ("head\n");

    return;
}

void add_node (node **f, node **r, int i)
{
    node *t;

    t = malloc (sizeof (node));
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

int main (void)
{
    node *f = NULL;
    node *r = NULL;
    int   i;

    for (i=1; i<=10; i++) {
        add_node (&f, &r, i);
    }

    printf ("\nqueue: ");

    print_queue (f);

    return (0);
}
