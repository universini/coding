#include <stdio.h>
#include <stdlib.h>

struct list {
    struct list *next;
    int          num;

};

typedef struct list node;

void print_list (node *n)
{
    while (n != NULL) {
        printf ("%d->", n->num);
        n = n->next;
    }

    printf ("NULL\n");

    return;
}

void insert_sorted (node **h, node *n)
{
    node *t = *h;

    if ((*h) == NULL ||
        (*h)->num >= n->num) {
        n->next = *h;
        *h = n;
    } else {
        while (t->next != NULL &&
            n->num >= t->next->num) {
            t = t->next;
        }

        n->next = t->next;
        t->next = n;
    }

    return;
}

node* create_node (int i)
{
    node *t;

    t = malloc (sizeof (node));
    t->num = i;
    t->next = NULL;

    return (t);
}

int main (void)
{
    node *n = NULL;
    node *nd;

    nd = create_node(2);
    insert_sorted(&n, nd);

    nd  = create_node(3);
    insert_sorted(&n, nd);

    nd = create_node(8);
    insert_sorted(&n, nd);

    nd = create_node(4);
    insert_sorted(&n, nd);

    nd = create_node(5);
    insert_sorted(&n, nd);

    nd = create_node(1);
    insert_sorted(&n, nd);

    nd = create_node(2);
    insert_sorted(&n, nd);

    printf ("\nLinked List: ");
    print_list (n);
    printf("\n");
    return (0);
}

