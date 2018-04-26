#include <stdio.h>
#include <malloc.h>

typedef struct node_s {
    struct node_s *prev;
    struct node_s *next;
    int            data;
} node_t;

void print_list (node_t *n)
{
    printf ("null <-> ");
    while (n != NULL) {
        printf ("%d <-> ", n->data);
        n = n->next;
    }

    printf ("null\n");
    return;
}

void delete_node (node_t **n, int num)
{
    node_t *t = *n;
    node_t *p;

    if ((*n)->data == num) {
        *n = (*n)->next;
        (*n)->prev = NULL;
        free (t);
    } else {
        while (t->next != NULL) {
            p = t;
            t = t->next;
            if (t->data == num) {
                p->next = t->next;
                t->next->prev = p;
                free (t);
            }
        }
    }

    return;
}

void insert_list (node_t **n, int num)
{
    node_t *t = *n;
    node_t *r;

    if (*n == NULL) {
        *n = malloc (sizeof (node_t));
        (*n)->prev = NULL;
        (*n)->next = NULL;
        (*n)->data = num;
    } else {
        while (t->next != NULL) {
            t = t->next;
        }

        r = malloc (sizeof (node_t));
        r->data = num;
        r->next = NULL;
        r->prev = t;
        t->next = r;
    }

    return;
}

int main (void)
{
    node_t *n = NULL;
    int     i;

    for (i=0; i<10; i++) {
        insert_list (&n, i+1);
    }

    print_list (n);
    delete_node (&n, 1);
    print_list (n);
    delete_node (&n, 5);
    print_list (n);

    return (0);
}

