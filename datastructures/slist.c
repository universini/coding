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

void delete_dup (node **s)
{
    node *t = *s;
    node *n;

    while (t->next != NULL) {
        n = t->next;
        if (t->num == n->num) {
            t->next = n->next;
            free (n);
        }

        t = t->next;
    }

    return;
}

void reverse_list (node **n)
{
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

void delete_node (node **n, int i)
{
    node *p, *t = *n;

    if ((*n)->num == i) {
        *n = (*n)->next;
        free (t);
    } else {
        while (t->next != NULL) {
            p = t;
            t = t->next;
            if (t->num == i) {
                p->next = t->next;
                free (t);
            }
        }
    }

    return;
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

int hasdup (node *n)
{
    node *t1 = n;
    node *t2 = n;

    while (t1 && t2 && t2->next) {
        t1 = t1->next;
        t2 = t2->next->next;

        if (t1 == t2) return (1);
    }

    return (0);
}

int main (void)
{
    node *n = NULL;
    int   i;

    for (i=1; i<=5; i++) {
        add_node (&n, i);
    }

    /* add dup */
    add_node (&n, 10);

    printf ("\noriginal linked list: ");

    print_list (n);

    reverse_list (&n);

    printf ("reversed linked list: ");

    print_list (n);

    delete_dup (&n);

    print_list (n);

    printf ("deleted duplicate num\n");

    printf ("enter number to be deleted: ");

    scanf ("%d", &i);

    delete_node (&n, i);

    print_list (n);

    //n->next->next->next = n;

    printf ("hasdup: %s\n", hasdup(n)?"true":"false");

    return (0);
}
