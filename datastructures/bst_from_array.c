#include <stdio.h>
#include <malloc.h>

struct bt_node {
    struct bt_node *left;
    struct bt_node *right;
    int             data;
    
};

typedef struct bt_node btnode;

void bst_print_inorder (btnode *node)
{
    if (node == NULL) return;
    else {
        bst_print_inorder (node->left);
        printf ("%d ", node->data);
        bst_print_inorder (node->right);
    }
}

btnode *bst_insert (int data)
{
    btnode *node;
    
    node = malloc (sizeof (struct bt_node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    
    return (node);
}

btnode *bst_from_array (int     array[],
                        int     start,
                        int     end)
{
    btnode *root;
    int     mid;
    
    if (start > end) return (NULL);
    
    mid = (start+end)/2;
    root = bst_insert (array[mid]);
 
    root->left = bst_from_array (array, start, mid-1);
    root->right = bst_from_array (array, mid+1, end);
     
    return (root);
}

int bst_size (btnode *node)
{
    if (node == NULL)
        return (0);
    else
        return (bst_size (node->left) + 1 + bst_size (node->right));
}

int main (void)
{
    btnode *root = NULL;
    int     array[] = {2, 6, 9, 16, 19, 28, 31, 45, 58};
    int     start = 0;
    int     end = sizeof (array)/sizeof (array[0]);
    
    root = bst_from_array (array, start, end-1);
    
    bst_print_inorder (root);
    printf ("\n");
    
    printf ("Nodes in BST: %d\n", bst_size (root));

    return (0);
}

