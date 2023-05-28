#include <stdio.h>
#include <malloc.h>

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

void ser_tree(btree_t *node, FILE *fp) {
  if (!node) {
    fprintf(fp, "%d ", -1);
    return;
  }

  fprintf(fp, "%d ", node->num);
  ser_tree(node->left, fp);
  ser_tree(node->right, fp);
}

void deser_tree(btree_t **node, FILE *fp) {
  int n;

  if (!fscanf(fp, "%d ", &n) || n == -1) {
    return;
  }

  *node = get_node(n);
  deser_tree(&(*node)->left, fp);
  deser_tree(&(*node)->right, fp);
}

int main(void) {
  FILE *fp = NULL;
  btree_t *new_root = NULL;
  btree_t *root = get_node(20);

  root->left = get_node(17);
  root->left->left = get_node(12);
  root->left->right = get_node(19);

  root->right = get_node(31);
  root->right->left = get_node(26);

  print_inorder(root);
  printf("\n");

  fp = fopen("ser_deser.txt", "w");
  ser_tree(root, fp);
  fclose(fp);

  fp = fopen("ser_deser.txt", "r");
  deser_tree(&new_root, fp);
  fclose(fp);

  print_inorder(new_root);
  printf("\n");

  return (0);
}
