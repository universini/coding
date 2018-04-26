#include <stdio.h>
#include <malloc.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct b_tree {
    struct b_tree *left;
    struct b_tree *right;
    int            data;
};

typedef struct b_tree btree;

int height (btree *node)
{
    if (node == NULL)
        return (0);
    else
        return(MAX(height(node->left), height(node->right)) + 1);
}

int find_min (btree *node)
{
    if (node == NULL)
        return (-1);

    while (node->left != NULL)
        node = node->left;

    return (node->data);
}

int find_max (btree *node)
{
    if (node == NULL)
        return (-1);

    if (node->right != NULL)
        node = node->right;

    return (node->data);
}

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

void preorder (btree *node)
{
    if (node != NULL) {
        printf ("%d ", node->data);
        preorder (node->left);
        preorder (node->right);
    } else {
        return;
    }
}

void postorder (btree *node)
{
    if (node != NULL) {
        postorder (node->left);
        postorder (node->right);
        printf ("%d ", node->data);
    } else {
        return;
    }
}

void insert (btree **node, int data)
{
    if (*node == NULL) {
        *node = malloc (sizeof (struct b_tree));
        (*node)->left = NULL;
        (*node)->right = NULL;
        (*node)->data = data;
    } else {
        if (data < (*node)->data) {
            insert (&((*node)->left), data);
        } else {
            insert (&((*node)->right), data);
        }
    }
    
    return;
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
        insert (&node, d);
    }

    printf ("\n");
    inorder (node);
    printf ("\n");
    
    preorder (node);
    printf ("\n");
    
    postorder (node);
    printf ("\n");
    
    printf ("min: %d and max: %d\n", find_min(node), find_max(node));
    printf ("height: %d\n", height(node));

    return (0);
}

