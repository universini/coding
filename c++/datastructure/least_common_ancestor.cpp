#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to find the lowest common ancestor of two nodes in a binary tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if (root == NULL || root == p || root == q) {
        return root;
    }

    // Check the left subtree for the lowest common ancestor
    struct TreeNode* left = lowestCommonAncestor(root->left, p, q);
    // Check the right subtree for the lowest common ancestor
    struct TreeNode* right = lowestCommonAncestor(root->right, p, q);

    // If both nodes are found in different subtrees, the current root is the lowest common ancestor
    if (left != NULL && right != NULL) {
        return root;
    }

    // If one of the nodes is found, return it (this means the other node is either in the current subtree or its subtree)
    return (left != NULL) ? left : right;
}

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    // Create the binary tree
    struct TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    root->right->left = createNode(0);
    root->right->right = createNode(8);

    // Nodes to find the lowest common ancestor
    struct TreeNode* p = root->left;
    struct TreeNode* q = root->left->right->right;

    // Find the lowest common ancestor
    struct TreeNode* lca = lowestCommonAncestor(root, p, q);

    // Output the value of the lowest common ancestor
    printf("Lowest Common Ancestor: %d\n", lca->val);

    // Free allocated memory (assuming a function to free the tree nodes)
    // freeTree(root);

    return 0;
}
