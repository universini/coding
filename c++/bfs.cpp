#include<iostream>
#include<queue>
using namespace std;

typedef struct bnode_s {
	int val;
	struct bnode_s *left, *right;
} bnode_t;

void insert(bnode_t **root, int val)
{
	if (*root == NULL) {
		*root = new bnode_t;
		(*root)->val = val;
		(*root)->left = (*root)->right = NULL;
	} else if (val < (*root)->val) {
		insert(&(*root)->left, val);
	} else {
		insert(&(*root)->right, val);
	}
}

void inorder(bnode_t *root)
{
	if (root == NULL) return;

	inorder(root->left);
	cout << " " << root->val;
	inorder(root->right);
}

void bfs(bnode_t *root)
{
	queue<bnode_t*> q;

	q.push(root);

	while (!q.empty()) {
		bnode_t *n = q.front();
		q.pop();
		cout << " " << n->val;

		if (n->left != NULL) {
			q.push(n->left);
		}

		if (n->right != NULL) {
			q.push(n->right);
		}
	}
}

int main(void)
{
	bnode_t *bt = NULL;

	insert(&bt, 10);
	insert(&bt, 5);
	insert(&bt, 1);
	insert(&bt, 40);
	insert(&bt, 100);

	inorder(bt);
	cout << "\n";

	bfs(bt);
	cout << "\n";

	return(0);
}


