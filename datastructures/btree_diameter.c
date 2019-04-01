#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a)>(b) ? (a) : (b))

typedef struct btree_s {
	struct btree_s *left;
	struct btree_s *right;
	int data;
} btree_t;

btree_t *btree_get_node(int num)
{
	btree_t *node;

	node = malloc(sizeof(btree_t));
	node->left = node->right = NULL;
	node->data = num;

	return(node);
}

int btree_height(btree_t *root)
{
	if (!root) {
		return(0);
	} else {
		return(1 + MAX(btree_height(root->left),
				btree_height(root->right)));
	}
}

void btree_dump(btree_t *root)
{
	if (root) {
		btree_dump(root->left);
		printf("%d ", root->data);
		btree_dump(root->right);
	}
}

int btree_diameter(btree_t *root)
{
	int left_height, right_height, left_width, right_width;

	if (!root) {
		return(0);
	}

	left_height = btree_height(root->left);
	right_height = btree_height(root->right);

	left_width = btree_diameter(root->left);
	right_width = btree_diameter(root->right);

	return(MAX(1+left_height+right_height, MAX(left_width, right_width)));
}

int main(void)
{
	btree_t *root = btree_get_node(36);

	root->left = btree_get_node(25);
	root->left->left = btree_get_node(19);
	root->left->right = btree_get_node(22);
	root->left->left->right = btree_get_node(13);
	root->left->left->right->right = btree_get_node(15);

	root->right = btree_get_node(47);
	root->right->left = btree_get_node(39);
	root->right->right = btree_get_node(54);

	btree_dump(root);
	printf("\n");

	printf("%d\n", btree_diameter(root));

	return(0);
}

