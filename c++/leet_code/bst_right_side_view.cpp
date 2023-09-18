#include <iostream>
#include <vector>
#include <queue>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    
    if (root == nullptr) {
        return result;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        // number of nodes at current level
        int numNodes = q.size();

        // std::cout << "level size: " << numNodes << " qsize: " << q.size() << std::endl;

        // Traverse all nodes of current level
        for (int i = 1; i <= numNodes; ++i) {
        // for (int i = 0; i < numNodes; ++i) {
            TreeNode* temp = q.front();
            q.pop();

            if (i == numNodes) {
            // if (i == numNodes - 1) {
                // Push the rightmost node at this level
                result.push_back(temp->val);
            }

            if (temp->left) {
                q.push(temp->left);
            }

            if (temp->right) {
                q.push(temp->right);
            }
        }
    }

    return result;
}

// Utility function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    // Create a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);
    root->right->right = createNode(4);

    std::vector<int> rightView = rightSideView(root);

    std::cout << "Right Side View of the Binary Tree: ";
    for (int val : rightView) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete root->right->right;
    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
