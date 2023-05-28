#include <iostream>

using namespace std;

typedef struct bnode_s {
  int val;
  struct bnode_s *left, *right;
} bnode_t;

bnode_t *get_node(int val) {
  bnode_t *node = new bnode_t;

  node->val = val;
  node->left = node->right = NULL;
  return (node);
}

void print_bnodes(bnode_t *root) {
  if (root == NULL) return;

  print_bnodes(root->left);
  cout << root->val << " ";
  print_bnodes(root->right);
}

void mirror_tree(bnode_t *root) {
  bnode_t *temp;

  if (root == NULL) return;

  mirror_tree(root->left);
  mirror_tree(root->right);

  temp = root->left;
  root->left = root->right;
  root->left = temp;
}

void double_tree(bnode_t *root) {
  bnode_t *temp;

  if (root == NULL) return;

  double_tree(root->left);
  double_tree(root->right);

  temp = root->left;
  root->left = get_node(root->val);
  root->left->left = temp;
}

int main(void) {
  bnode_t *root;

  root = get_node(4);
  root->left = get_node(2);
  root->right = get_node(5);
  root->left->left = get_node(1);
  root->left->right = get_node(3);

  print_bnodes(root);
  cout << "\n";

  double_tree(root);

  print_bnodes(root);
  cout << "\n";

  mirror_tree(root);

  print_bnodes(root);
  cout << "\n";

  return (0);
}
