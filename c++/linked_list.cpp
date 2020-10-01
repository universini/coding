#include<iostream>

using namespace std;

typedef struct node_s {
	int data;
	struct node_s *next;
} node_t;

void dump_list(node_t *head)
{
	node_t *temp = head;
	
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

void insert_list(node_t **head, int data)
{
	node_t *temp = *head;
	
	if (NULL == temp) {
		*head = new node_t;
		(*head)->data = data;
		(*head)->next = NULL;
	} else {
		while(temp->next != NULL)
			temp = temp->next;
		
		temp->next = new node_t;
		temp->next->data = data;
		temp->next->next = NULL;
	}
}

void remove_list(node_t *head, int data)
{
	node_t *temp = head;
	node_t *prev;
	
	if(!head) return;
	
	if (head->data == data) {
		head = head->next;
		delete temp;
	} else {
		while(temp->next && temp->data != data) {
			prev = temp;
			temp = temp->next;
		}
		
		prev->next = temp->next;
		delete temp;
	}
}

node_t* reverse_list(node_t *head)
{
	node_t *temp, *rev = NULL;
	
	while (head != NULL) {
		temp = head->next;
		head->next = rev;
		rev = head;
		head = temp;
	}
	
	return(rev);
}

node_t* split_list(node_t *head)
{
	node_t *slow = head;
	node_t *fast = head;
	
	while(fast->next->next != NULL) {
		slow = slow->next;
		
		if (fast->next->next)
			fast = fast->next->next;
	}
	
	node_t *second = slow->next;
	slow->next = NULL;
	
	return(second);
}

int main(void)
{
	node_t *rev, *first = NULL, *second = NULL;
	
	for (int i=1; i<=10; i++)
		insert_list(&first, i);
	
	dump_list(first);
	cout << "\nAfter deleted 6\n";
	
	remove_list(first, 6);
	dump_list(first);
	insert_list(&first, 11);
	
	cout << "\nFirst split\n";
	second = split_list(first);
	dump_list(first);
	cout << "\nSecond split\n";
	dump_list(second);

	rev = reverse_list(second);
	cout << "\nAfter reversed\n";
	dump_list(rev);
	
	return(0);
}
