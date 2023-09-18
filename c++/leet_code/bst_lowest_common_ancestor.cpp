#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA) {
        return root; // Both nodes are found in left and right subtrees, so root is the LCA
    }

    return leftLCA ? leftLCA : rightLCA; // LCA is either in left or right subtree
}

// Utility function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(3);
    root->left = createNode(5);
    root->right = createNode(1);
    root->left->left = createNode(6);
    root->left->right = createNode(2);
    root->left->right->left = createNode(7);
    root->left->right->right = createNode(4);
    root->right->left = createNode(0);
    root->right->right = createNode(8);

    TreeNode* p = root->left;
    TreeNode* q = root->right;

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    std::cout << "Lowest Common Ancestor of nodes " << p->val << " and " << q->val << " is " << lca->val << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}
