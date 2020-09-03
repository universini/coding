#include<iostream>

using namespace std;

struct node_s {
	int data;
	struct node_s *next;
	
	node_s* get_node(int data)
	{
		node_s *n = new(node_s);
		n->data = data;
		n->next = NULL;
		
		return(n);
	}
	
	void show_list(struct node_s *h)
	{
		while(h != nullptr) {
			cout << h->data << " ";
			h = h->next;
		}
	}
};

int main(void)
{
	struct node_s *h;
	//struct node_s s;
	
	//h = s.get_node(10);
	//h->next = s.get_node(20);
	//h->next->next = s.get_node(30);

	//s.show_list(h);
	
	h = h->get_node(10);
	h->next = h->get_node(20);
	h->next->next = h->get_node(30);

	h->show_list(h);

	return(0);
}
