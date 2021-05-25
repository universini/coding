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

bnode_t *get_nth_node(bnode_t *root, int n) {
  if (root == NULL) return (root);

  while (n--) {
    get_nth_node(root->left, n);
    get_nth_node(root->right, n);
  }

  return (root);
}

int main(void) {
  bnode_t *root, *node;

  root = get_node(10);
  root->left = get_node(20);
  root->right = get_node(30);
  root->left->left = get_node(40);
  root->left->right = get_node(50);

  node = get_nth_node(root, 4);

  cout << node->val;
  cout << "\n";

  return (0);
}
