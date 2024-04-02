#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

// Iterative function to perform inorder traversal on the tree
std::vector<int> inorderIterative(TreeNode* root)
{
    std::vector<int> result;

    // create an empty stack
    std::stack<TreeNode*> stack;
 
    // start from the root node (set current node to the root node)
    TreeNode* curr = root;
 
    // if the current node is null and the stack is also empty, we are done
    while (!stack.empty() || curr != nullptr)
    {
        // if the current node exists, push it into the stack (defer it)
        // and move to its left child
        if (curr != nullptr)
        {
            stack.push(curr);
            curr = curr->left;
        }
        else
        {
            // otherwise, if the current node is null, pop an element from the stack,
            // print it, and finally set the current node to its right child
            curr = stack.top();
            stack.pop();
            result.push_back(curr->val);
            curr = curr->right;
        }
    }

    return result;
}

// Utility function to create a binary tree node
TreeNode* createNode(int val) {
    return new TreeNode(val);
}

int main() {
    std::vector<int> result;
    // Create a sample binary tree
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    std::cout << "In-order traversal:" << std::endl;
    result = inorderTraversal(root);

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    result = inorderIterative(root);

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete root->left->right;
    delete root->left->left;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
