#include <iostream>
#include <stack>

using namespace std;

typedef struct Node_s {
  struct Node_s *left, *right;
  int data;
} Node;

Node *insert_btree(Node *root, int data) {
  if (root == NULL) {
    root = new Node;
    root->data = data;
    root->left = root->right = NULL;
  } else {
    if (data < root->data) {
      root->left = insert_btree(root->left, data);
    } else {
      root->right = insert_btree(root->right, data);
    }
  }

  return (root);
}

void print_inorder_iterative(Node *root) {
  if (root == nullptr) return;

  stack<Node *> stack;

  Node *curr = root;

  while (!stack.empty() || curr != nullptr) {
    // if current node is not null, push it to the stack (defer it)
    // and move to its left child
    if (curr != nullptr) {
      stack.push(curr);
      curr = curr->left;
    } else {
      // else if current node is null, we pop an element from stack,
      // print it and finally set current node to its right child
      curr = stack.top();
      stack.pop();
      cout << curr->data << " ";
      curr = curr->right;
    }
  }

  cout << endl;
}

void print_preorder_iterative(Node *root) {
  if (root == nullptr) return;

  stack<Node *> stack;
  stack.push(root);

  while (!stack.empty()) {
    // pop a node from the stack and print it
    Node *curr = stack.top();
    stack.pop();

    cout << curr->data << " ";

    // right child is pushed first so that left child
    // is processed first in a FIFO order
    if (curr->right) stack.push(curr->right);
    if (curr->left) stack.push(curr->left);
  }

  cout << endl;
}

void print_postorder_iterative(Node *root) {
  stack<Node *> stk;
  stk.push(root);

  stack<int> out;

  while (!stk.empty()) {
    // pop a node from the stack
    Node *curr = stk.top();
    stk.pop();

    // push the data to output stack
    out.push(curr->data);

    // push left and right child of popped node
    if (curr->left) stk.push(curr->left);
    if (curr->right) stk.push(curr->right);
  }

  while (!out.empty()) {
    cout << out.top() << " ";
    out.pop();
  }

  cout << endl;
}

int main(void) {
  Node *root = NULL, *nroot;
  int a[] = {1, 2, 3, 4, 5};

  root = insert_btree(root, 15);
  root = insert_btree(root, 12);
  root = insert_btree(root, 25);
  root = insert_btree(root, 37);
  root = insert_btree(root, 18);
  root = insert_btree(root, 9);
  root = insert_btree(root, 16);

  print_preorder_iterative(root);
  print_inorder_iterative(root);
  print_postorder_iterative(root);

  return 0;
}