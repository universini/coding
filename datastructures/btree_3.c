#include <stdio.h>
#include <malloc.h>
#include <limits.h>

struct b_tree {
    struct b_tree *left;
    struct b_tree *right;
    int            data;
};

typedef struct b_tree btree;

void inorder (btree *node)
{
    if (node != NULL) {
        inorder (node->left);
        printf ("%d ", node->data);
        inorder (node->right);
    } else {
        return;
    }
}

btree* insert (btree *node, int data)
{
    if (node == NULL) {
        node = malloc (sizeof (struct b_tree));
        node->left = NULL;
        node->right = NULL;
        node->data = data;
    } else {
        if (data < node->data) {
            node->left = insert (node->left, data);
        } else {
            node->right = insert (node->right, data);
        }
    }
}

int main (void)
{
    btree *node = NULL;
    int    n, d;
    
    printf ("enter num of elements to be inserted: ");
    scanf ("%d", &n);
    
    while (n--) {
        printf ("enter data: ");
        scanf ("%d", &d);
        node = insert (node, d);
    }

    inorder (node);
    printf ("\n");

    return (0);
}

