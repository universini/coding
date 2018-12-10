#include <stdio.h>
#include <malloc.h>

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

node *split_half (node *s)
{
    node *fast = s;
    node *second;

    while (fast->next->next != NULL) {
        s = s->next;
        if (fast->next->next)
            fast = fast->next->next;
    }

    second = s->next;
    s->next = NULL;

    return(second);
}

void add_node (node **n, int i)
{
    node *t = *n;

    if (*n == NULL) {
        *n = malloc (sizeof (node));
        t = *n;
    } else {
        while (t->next != NULL) {
            t = t->next;
        }

        t->next = malloc (sizeof (node));
        t = t->next;
    }

    t->num = i;
    t->next = NULL;

    return;
}

int main (void)
{
    node *s, *n = NULL;
    int   i;

    for (i=1; i<=14; i++) {
        add_node (&n, i);
    }

    printf ("original linked list: \n");
    print_list (n);

    s = split_half(n);

    printf ("split linked lists: \n");
    print_list (n);
    print_list (s);

    return (0);
}
