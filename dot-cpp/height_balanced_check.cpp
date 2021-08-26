#include <iostream>
#include <utility>
#include <cmath>
using namespace std;

// Data structure to store a Binary Tree node
struct Node {
  int data;
  Node *left, *right;

  Node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// Recursive function to check if given binary tree is height balanced or not
int isHeightBalanced(Node* root, bool& isBalanced) {
  // base case: tree is empty or tree is not balanced
  if (root == nullptr || !isBalanced) return 0;

  // get height of left subtree
  int left_height = isHeightBalanced(root->left, isBalanced);

  // get height of right subtree
  int right_height = isHeightBalanced(root->right, isBalanced);

  // tree is unbalanced if absolute difference between height of
  // its left subtree and right subtree is more than 1
  if (abs(left_height - right_height) > 1) isBalanced = false;

  // return height of subtree rooted at current node
  return max(left_height, right_height) + 1;
}

// Main function to check if given binary tree is height balanced or not
bool isHeightBalanced(Node* root) {
  bool isBalanced = true;
  isHeightBalanced(root, isBalanced);

  return isBalanced;
}

int main() {
  Node* root = nullptr;
  /* Construct below tree
                        1
                      /   \
                 /     \
                2       3
               / \     /
              4   5   6
      */

  root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);
  root->right->left = new Node(6);

  isHeightBalanced(root) ? cout << "Yes" : cout << "No";

  return 0;
}
