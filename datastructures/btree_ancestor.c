#include<stdio.h>
#include<malloc.h>

#define false 0
#define true  1

typedef struct btree_ {
	struct btree_ *left;
	struct btree_ *right;
	int data;
} btree_t;

btree_t *create_node(int n)
{
	btree_t *node;

	node = malloc(sizeof(btree_t));
	node->left = node->right = NULL;
	node->data = n;

	return(node);
}

void print_nodes(btree_t *node)
{
	if (!node) return;
	else {
		print_nodes(node->left);
		printf("%d ", node->data);
		print_nodes(node->right);
	}
}

int print_ancestors(btree_t *node, int n)
{
	if (!node) return(false);
	if (node->data == n) return(true);
	if (print_ancestors(node->left, n) ||
		print_ancestors(node->right, n)) {
		printf("%d ", node->data);
		return(true);
	}

	return(false);
}

int main(void)
{
	btree_t *node = create_node(4);
	node->left = create_node(2);
	node->right = create_node(7);
	node->left->left = create_node(1);
	node->left->right = create_node(3);
	node->right->left = create_node(5);

	print_nodes(node);
	printf("\n");
	print_ancestors(node, 7);
	printf("\n");

	return(0);
}
 
