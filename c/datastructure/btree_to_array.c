#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef struct btree_ {
  struct btree_ *left;
  struct btree_ *right;
  int data;
} btree_t;

btree_t *create_node(int n) {
  btree_t *node;

  node = malloc(sizeof(btree_t));
  node->left = node->right = NULL;
  node->data = n;

  return (node);
}

void print_nodes(btree_t *root) {
  if (!root)
    return;
  else {
    print_nodes(root->left);
    printf("%d ", root->data);
    print_nodes(root->right);
  }
}

int count_nodes(btree_t *root) {
  if (root == NULL)
    return (0);
  else
    return (count_nodes(root->left) + count_nodes(root->right) + 1);
}

int i = 0;

void build_array_from_btree(btree_t *root, int *arr) {
  if (root == NULL) return;

  build_array_from_btree(root->left, arr);
  arr[i++] = root->data;
  build_array_from_btree(root->right, arr);
}

int main(void) {
  int *a = NULL;
  int size = 0;
  btree_t *root = create_node(4);
  root->left = create_node(2);
  root->right = create_node(7);
  root->left->left = create_node(1);
  root->left->right = create_node(3);
  root->right->left = create_node(5);

  print_nodes(root);
  printf("\n");

  size = count_nodes(root);
  printf("size = %d\n", size);
  a = malloc(size * sizeof(int));

  build_array_from_btree(root, a);

  for (int i = 0; i < size; i++) printf("%d ", a[i]);
  printf("\n");

  return (0);
}
