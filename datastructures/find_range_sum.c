#include<stdio.h>
#include<malloc.h>

typedef struct bnode_s {
	int val;
	struct bnode_s *left, *right;
} bnode_t;

bnode_t *get_node(int val)
{
	bnode_t *n;

	n = malloc(sizeof(bnode_t));
	n->val = val;
	n->left = n->right = NULL;

	return(n);
}

int range_sum(bnode_t *root, int L, int R)
{
	static int sum = 0;

	if (!root) return(0);

	if (root->val >= L && root->val <= R) {
		sum += root->val;
	}

	range_sum(root->left, L, R);
	range_sum(root->right, L, R);

	return(sum);
}

void print_inorder(bnode_t *root)
{
	if (!root) return;

	print_inorder(root->left);
	printf("%d ", root->val);
	print_inorder(root->right);
}

int main(void)
{
	bnode_t *root = NULL;

	root = get_node(10);
	root->left = get_node(5);
	root->left->left = get_node(1);
	root->right = get_node(50);
	root->right->left = get_node(40);
	root->right->right = get_node(100);

	print_inorder(root);

	printf("Range sum: %d\n", range_sum(root, 5, 50));

	return(0);
}

