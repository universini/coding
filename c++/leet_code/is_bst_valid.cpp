#include <iostream>
#include <climits>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool isValidBSTUtil(TreeNode* root,
                    long long minVal,
                    long long maxVal) {
    if (root == nullptr) return true;

    if (root->val <= minVal || root->val >= maxVal)
        return false;

    return isValidBSTUtil(root->left, minVal, root->val) &&
           isValidBSTUtil(root->right, root->val, maxVal);
}

bool isValidBST(TreeNode* root) {
    return isValidBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// Utility function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(2);
    root->left = createNode(1);
    root->right = createNode(3);

    std::cout << "Is the given tree a valid BST? "
              << (isValidBST(root) ? "Yes" : "No") << std::endl;

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
