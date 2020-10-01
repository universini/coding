#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct {
    int   depth;
    int   count;
    int  *data;
} stack;

void push (stack *s, int *val)
{
    s->data = val;
    s->count++;
}

int pop (stack *s)
{
    s->count--;
    return (*(int *)s->data);
}

void init_stack (stack *s, int l)
{
    s->depth = l;
    s->count = 0;
    s->data = malloc (l*sizeof (int));
    assert (s->data != NULL);

    return;
}

int main (void)
{
    stack s;
    int   i;
    int   l=8;

    init_stack (&s, l);

    for (i=1; i<=l; i++) {
        push(&s, &i);
    }

    for (i=0; i<l; i++) {
        printf ("stack elem: %d\n", pop(&s));
    }

    return (0);
}
