#include <stdio.h>
#include <stdlib.h>

typedef struct btree_s {
  int num;
  struct btree_s *left, *right;
} btree_t;

btree_t *get_node(int n) {
  btree_t *node;

  node = malloc(sizeof(btree_t));
  node->num = n;
  node->left = node->right = NULL;

  return (node);
}

void print_inorder(btree_t *node) {
  if (node != NULL) {
    print_inorder(node->left);
    printf("%d ", node->num);
    print_inorder(node->right);
  }
}

btree_t *clone_tree(btree_t *node) {
  btree_t *new_node;

  if (!node) return (node);

  new_node = get_node(node->num);
  new_node->left = clone_tree(node->left);
  new_node->right = clone_tree(node->right);

  return (new_node);
}

int main(void) {
  btree_t *new_root = NULL;
  btree_t *root = get_node(20);

  root->left = get_node(17);
  root->left->left = get_node(12);
  root->left->right = get_node(19);

  root->right = get_node(31);
  root->right->left = get_node(26);

  print_inorder(root);
  printf("\n");

  new_root = clone_tree(root);

  print_inorder(new_root);
  printf("\n");

  return (0);
}
