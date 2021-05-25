#include <stdio.h>
#include <malloc.h>

typedef struct btree_s {
  struct btree_s *left;
  struct btree_s *right;
  int data;
} btree_t;

void btree_preorder(btree_t *root) {
  if (!root) return;

  printf("%d ", root->data);
  btree_preorder(root->left);
  btree_preorder(root->right);
}

void btree_inorder(btree_t *root) {
  if (!root) return;

  btree_inorder(root->left);
  printf("%d ", root->data);
  btree_inorder(root->right);
}

void btree_postorder(btree_t *root) {
  if (!root) return;

  btree_postorder(root->left);
  btree_postorder(root->right);
  printf("%d ", root->data);
}

btree_t *btree_find_min(btree_t *root) {
  if (!root) {
    return (root);
  } else {
    return (btree_find_min(root->left));
  }
}

btree_t *btree_find_node(btree_t *root, int data) {
  if (!root) {
    return (root);
  } else {
    if (root->data == data) {
      return (root);
    } else {
      if (data < root->data) {
        btree_find_node(root->left, data);
      } else {
        btree_find_node(root->right, data);
      }
    }
  }
}

btree_t *btree_delete(btree_t *root, int data) {
  btree_t *temp;

  if (!root) {
    return (root);
  }

  if (data < root->data) {
    root->left = btree_delete(root->left, data);
  } else if (data > root->data) {
    root->right = btree_delete(root->right, data);
  } else { /* Case 1: no child */
    if (root->left == NULL && root->right == NULL) {
      free(root);
      root = NULL;
    } else if (root->left == NULL) {
      /* Case 2-1: one child */
      temp = root;
      root = root->right;
      free(temp);
    } else if (root->right == NULL) {
      /* Case 2-2: one child */
      temp = root;
      root = root->left;
      free(temp);
    } else { /* Case 3: two children */
      temp = btree_find_min(root->right);
      root->data = temp->data;
      root->right = btree_delete(root->right, temp->data);
    }
  }

  return (root);
}

#ifdef BFT_CQ_READY
void btree_bft(btree_t *root) {
  btree_t *temp;

  if (!btree) {
    return;
  }

  temp = root;
  q_push(bqueue, temp);
  while (is_not_empty(bqueue)) {
    /* Get first node from Q */
    temp = q_pop(bqueue);
    printf("%d ", temp->data);

    if (temp->left != NULL) {
      q_push(bqueue, temp->left);
    }

    if (temp->right != NULL) {
      q_push(bqueue, temp->right);
    }
  }

  return;
}
#endif

void btree_insert(btree_t **root, int data) {
  if (!*root) {
    *root = malloc(sizeof(btree_t));
    if (*root == NULL) {
      printf("malloc failed\n");
      return;
    } else {
      (*root)->left = NULL;
      (*root)->right = NULL;
      (*root)->data = data;
    }
  } else {
    if (data <= (*root)->data) {
      btree_insert(&(*root)->left, data);
    } else {
      btree_insert(&(*root)->right, data);
    }
  }

  return;
}

int main(void) {
  btree_t *n, *root = NULL;
  int i;

  btree_insert(&root, 26);
  btree_insert(&root, 46);
  btree_insert(&root, 11);
  btree_insert(&root, 19);
  btree_insert(&root, 16);
  btree_insert(&root, 7);
  btree_insert(&root, 28);
  btree_insert(&root, 56);
  btree_insert(&root, 36);
  btree_insert(&root, 29);
  btree_insert(&root, 21);
  btree_insert(&root, 5);
  btree_insert(&root, 6);
  btree_insert(&root, 2);

  btree_preorder(root);
  printf("\n");
  btree_inorder(root);
  printf("\n");
  btree_postorder(root);
  printf("\n");

  n = btree_find_node(root, 56);
  printf("Found: %d\n", n->data);

  root = btree_delete(root, 29);
  btree_inorder(root);
  printf("\n");
  return (0);
}
