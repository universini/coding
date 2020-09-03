#include<iostream>
#include<vector>
#include<stack>
#include<queue>

using namespace std;

typedef struct btree_s {
	int data;
	btree_s *left, *right;
} btree_t;

void preorder_btree(btree_t *root)
{
	if (!root) return;
	
	cout << root->data << " ";
	preorder_btree(root->left);
	preorder_btree(root->right);	
}

void insert_btree(btree_t **root, int data)
{
	if (!*root){ 
		*root = new btree_t;
		(*root)->data = data;
		(*root)->left = (*root)->right = NULL;
	} else {
		if (data < (*root)->data)
			insert_btree(&(*root)->left, data);
		else
			insert_btree(&(*root)->right, data);
	}
}

void replace_bst_preorder(btree_t *root, queue<int>& q)
{
	if (!root) return;
	
	root->data = q.front();
	q.pop();
	replace_bst_preorder(root->left, q);
	replace_bst_preorder(root->right, q);
}

void insert_q_inorder(btree_t *root, queue<int>& q)
{
	if (!root) return;
	
	insert_q_inorder(root->left, q);
	q.push(root->data);
	insert_q_inorder(root->right, q);
}

void convert_btree(btree_t *root)
{
	queue<int> q;
	
	insert_q_inorder(root, q);
	replace_bst_preorder(root, q);
}

void level_print_btree(btree_t *root)
{
	queue<btree_t*> nodes;
	
	nodes.push(root);

	while(!nodes.empty()) {
		btree_t *node = nodes.front();
		nodes.pop();
		
		cout << node->data << " ";
		
		if (node->left) nodes.push(node->left);
		if (node->right) nodes.push(node->right);
	}
}

int main(void)
{
	btree_t *root = NULL;
	vector<int> keys;
	
	keys.push_back(5);
	keys.push_back(3);
	keys.push_back(2);
	keys.push_back(4);
	keys.push_back(8);
	keys.push_back(6);
	keys.push_back(10);
	
	for(int i=0; i<keys.size(); i++)
	{
		insert_btree(&root, keys[i]);
	}
	
	convert_btree(root);
	cout << "Level order output:\n";
	level_print_btree(root);
	cout << "\nPre-order output:\n";
	preorder_btree(root);
	
	return(0);
}
