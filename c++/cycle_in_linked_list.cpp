#include <iostream>
#include <unordered_set>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to create a new node with the given data and
// pushes it onto the front of the list
void push(Node*& headRef, int data)
{
	// create a new linked list node from heap
	Node* newNode = new Node;

	newNode->data = data;
	newNode->next = headRef;
	headRef = newNode;
}

// Function to detect Cycle in a linked list using Hashing
bool detectCycle(Node *head)
{
	Node *curr = head;
	unordered_set<Node*> set;

	// traverse the list
	while (curr)
	{
		// return false if we already have seen this node before
		if (set.find(curr) != set.end())
			return true;

		// insert current node into the set
		set.insert(curr);

		// move to the next node
		curr = curr->next;
	}

	// we reach here if list does not contain any cycle
	return false;
}

// Detect Cycle in a linked list
int main()
{
	// input keys
	int keys[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(keys) / sizeof(keys[0]);

	Node* head = nullptr;
	for (int i = n - 1; i >= 0; i--)
		push(head, keys[i]);

	// insert cycle
	head->next->next->next->next->next = head->next->next;

	if (detectCycle(head))
		cout << "Cycle Found";
	else
		cout << "No Cycle Found";

	return 0;
}
