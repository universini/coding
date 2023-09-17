#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int maxDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;
    else
        return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// Utility function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int minDepth(TreeNode* root) {
    if (root == nullptr)
        return 0;

    if (root->left == nullptr)
        return 1 + minDepth(root->right);

    if (root->right == nullptr)
        return 1 + minDepth(root->left);

    return 1 + std::min(minDepth(root->left), minDepth(root->right));
}

int main() {
    int depth = 0;
    // Create a sample binary tree
    TreeNode* root = createNode(3);
    root->left = createNode(9);
    root->right = createNode(20);
    root->right->left = createNode(15);
    root->right->right = createNode(7);

    depth = maxDepth(root);
    std::cout << "Maximum depth of the binary tree: " << depth << std::endl;

    depth = minDepth(root);
    std::cout << "Minimum depth of the binary tree: " << depth << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
