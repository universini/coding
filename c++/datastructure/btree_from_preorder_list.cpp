#include <iostream>

using namespace std;

typedef struct bnode_s {
  int val;
  struct bnode_s *left, *right;
} bnode_t;

void bst_print(bnode_t *root) {
  if (root == NULL) return;
  bst_print(root->left);
  cout << root->val << " ";
  bst_print(root->right);
}

bnode_t *get_node(int val) {
  bnode_t *node;

  node = new bnode_t;
  node->val = val;
  node->left = node->right = NULL;
  return (node);
}

/*
    Construct the root node of BST, which would be the first key in the preorder sequence.
    Find index i of the first key in the preorder sequence, which is greater than the root node.
    Recur for the left subtree with keys in the preorder sequence that appears before the i'th index (excluding the first index).
    Recur for the right subtree with keys in the preorder sequence that appears after the i'th index (including the i'th index).

    Let’s consider the preorder traversal {15, 10, 8, 12, 20, 16, 25} to make the context more clear.

    The first item in the preorder sequence 15 becomes the root node.
    Since 20 is the first key in the preorder sequence, which greater than the root node,
    the left subtree consists of keys {10, 8, 12} and the right subtree consists of keys {20, 16, 25}.
    To construct the complete BST, recursively repeat the above steps for preorder sequence {10, 8, 12} and {20, 16, 25}.
*/
bnode_t *bst_build(int a[], int start, int end) {
  bnode_t *root;
  int i;

  if (start > end) return (NULL);

  root = get_node(a[start]);

  for (i = start; i < end; i++)
    if (a[i] > root->val) break;

  root->left = bst_build(a, start + 1, i - 1);
  root->right = bst_build(a, i, end);

  return (root);
}

int main(void) {
  int a[] = {15, 10, 8, 12, 20, 16, 25};
  // int a[] = {8,5,1,7,10,12};
  int size = sizeof(a) / sizeof(a[0]);
  bnode_t *root;

  root = bst_build(a, 0, size);
  bst_print(root);

  return (0);
}
