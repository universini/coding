#include<stdio.h>
#include<malloc.h>

typedef struct node_s {
	struct node_s *next;
	int data;
} node_t;

void print_list(node_t *n)
{
	node_t *t = n;

	while(t != NULL) {
		printf("%d ", t->data);
		t = t->next;
	}
}

node_t *getnode(int n)
{
	node_t *t;

	t = malloc(sizeof(node_t));
	if (!t) {
		return(NULL);
	}

	t->data = n;
	t->next = NULL;

	return(t);
}

node_t *merge_reversed(node_t *n1, node_t *n2)
{
	node_t *r = NULL;
	node_t *t;

	if (!n1 && !n2) return(NULL);
	if (!n1) return(n2);
	if (!n2) return(n1);

	while (n1 && n2) {
		if (n1->data <= n2->data) {
			t = n1->next;
			n1->next = r;
			r = n1;
			n1 = t;
		} else {
			t = n2->next;
			n2->next = r;
			r = n2;
			n2 = t;
		}
	}

	while(n1) {
		t = n1->next;
		n1->next = r;
		r = n1;
		n1 = t;
	}

	while(n2) {
		t = n2->next;
		n2->next = r;
		r = n2;
		n2 = t;
	}

	return(r);
}

int main(void)
{
	node_t *n1 = getnode(3);
	node_t *n2 = getnode(7);

	if (n1) {
		n1->next = getnode(4);
		n1->next->next = getnode(5);
		n1->next->next->next = getnode(6);
	}

	if (n2) {
		n2->next = getnode(8);
		n2->next->next = getnode(9);
	}

	print_list(n1);
	printf("\n");
	print_list(n2);
	printf("\n");

	print_list(merge_reversed(n1, n2));
	printf("\n");

	return(0);
}

