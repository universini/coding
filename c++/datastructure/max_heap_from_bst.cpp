#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root, std::vector<int>& values) {
    if (root == nullptr)
        return;

    inorderTraversal(root->left, values);
    values.push_back(root->val);
    inorderTraversal(root->right, values);
}

TreeNode* insertMaxHeap(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val > root->val) {
        TreeNode* temp = new TreeNode(val);
        temp->left = root;
        return temp;
    } else {
        root->right = insertMaxHeap(root->right, val);
    }

    return root;
}

TreeNode* heapifyBST(TreeNode* root) {
    std::vector<int> values;
    inorderTraversal(root, values);

    TreeNode* newRoot = nullptr;

    for (const auto& val : values) {
        newRoot = insertMaxHeap(newRoot, val);
    }

    return newRoot;
}

// Utility function to print the max-heap
void printHeap(TreeNode* root) {
    if (root == nullptr)
        return;

    std::cout << root->val << " ";
    printHeap(root->left);
    printHeap(root->right);
}

/*
 * Heapifying a binary search tree (BST) typically means reorganizing
 * the BST to transform it into a binary heap while maintaining the
 * heap property. A binary heap is a complete binary tree where the
 * value of each node is greater (for a max-heap) or lesser (for a min-heap)
 * than the values of its children.
 * To heapify a BST into a max-heap, you can perform an in-order traversal
 * of the BST to extract the values in a sorted order and then construct
 * the max-heap.
 */
int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    std::cout << "Original Binary Search Tree:" << std::endl;
    printHeap(root);
    std::cout << std::endl;

    TreeNode* maxHeapRoot = heapifyBST(root);

    std::cout << "Binary Max Heap:" << std::endl;
    printHeap(maxHeapRoot);
    std::cout << std::endl;

    return 0;
}
