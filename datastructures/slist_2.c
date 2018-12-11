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

int list_len(node *l)
{
    int c = 0;

    while (l->next) {
        c++;
        l = l->next;
    }

    return(c);
}

node *find_merge_point_node(node *n1, node *n2, int ld)
{
    for (int i=0; i<ld; i++) {
        if (!n1)
            return (NULL);
        n1 = n1->next;
    }

    while (n1 && n2) {
        if (n1 == n2)
            return (n1);
        n1 = n1->next;
        n2 = n2->next;
    }

    return (NULL);
}

node *find_merge_point(node *n1, node *n2)
{
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

	s = find_merge_point(n, s);
	if (s) printf("Merge Point: %d\n", s->num);

    return (0);
}
