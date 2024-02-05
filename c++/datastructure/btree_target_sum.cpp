#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool hasPathSum(TreeNode* root, int sum) {
    // Base case: If the current node is null, return false
    if (root == nullptr) {
        return false;
    }

    // If the current node is a leaf and its value equals the remaining sum,
    // then a path with the target sum is found
    if (root->left == nullptr &&
        root->right == nullptr &&
        sum - root->val == 0) {
        return true;
    }

    // Recursively check for the sum in the left and right subtrees
    return hasPathSum(root->left, sum - root->val) ||
           hasPathSum(root->right, sum - root->val);
}

int main() {
    // Example usage:
    // Constructing a BST: 
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \      \
    //  7    2      1

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;

    if (hasPathSum(root, targetSum)) {
        cout << "There exists a path with sum " << targetSum << "." << endl;
    } else {
        cout << "No path found with sum " << targetSum << "." << endl;
    }

    // Clean up the allocated memory
    // (Assuming a function to free the memory of the tree nodes)
    // freeTree(root);

    return 0;
}
