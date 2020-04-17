#include<iostream>

using namespace std;

class list_node {
	public:
		int        data;
		list_node *next;
};


void print(list_node *head)
{
	list_node *t = head;

	while(t != NULL)
	{
		cout << t->data << " ";
		t = t->next;
	}

	cout << "\n";
}

void swap(list_node **head, int m, int n)
{
	list_node *x = *head, *xprev, *y = *head, *yprev;

	if(m == n) return;
	if(*head == NULL) return;

	while(x != NULL && x->data != m) 
	{
		xprev = x;
		x = x->next;
	}

	while(y != NULL && y->data != n)
	{
		yprev = y;
		y = y->next;
	}

	if (x == NULL || y == NULL) return;

	if(x)
	{
		yprev->next = x;
		x->next = y->next;
	}

	if(y)
	{
		xprev->next = y;
		y->next = x->next;
	}

	//list_node *t = xprev->next;
	//yprev->next = xprev->next;
	//xprev->next = t;
}

void insert(list_node **head, int n)
{
	list_node *t = new list_node();

	t->data = n;
	t->next = *head;
	*head = t;
}

int main(void)
{
	list_node *head = NULL;

	insert(&head, 70);
	insert(&head, 60);
	insert(&head, 50);
	insert(&head, 40);
	insert(&head, 30);
	insert(&head, 20);
	insert(&head, 10);

	print(head);
	swap(&head, 30, 50);
	print(head);

	return(0);
}

