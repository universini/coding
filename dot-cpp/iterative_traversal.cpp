// Iterative function to perform in-order traversal of the tree
void inorderIterative(Node *root) {
  // return if tree is empty
  if (root == nullptr) return;

  // create an empty stack
  stack<Node *> stack;

  // start from root node (set current node to root node)
  Node *curr = root;

  // if current node is null and stack is also empty, we're done
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
}

// Iterative function to perform pre-order traversal of the tree
void preorderIterative(Node *root) {
  // return if tree is empty
  if (root == nullptr) return;

  // create an empty stack and push root node
  stack<Node *> stack;
  stack.push(root);

  // run till stack is not empty
  while (!stack.empty()) {
    // pop a node from the stack and print it
    Node *curr = stack.top();
    stack.pop();

    cout << curr->data << " ";

    // push right child of popped node to the stack
    if (curr->right) stack.push(curr->right);

    // push left child of popped node to the stack
    if (curr->left) stack.push(curr->left);

    // important note - right child is pushed first so that left child
    // is processed first (FIFO order)
  }
}

// Iterative function to perform post-order traversal of the tree
void postorderIterative(Node *root) {
  // create an empty stack and push root node
  stack<Node *> stk;
  stk.push(root);

  // create another stack to store post-order traversal
  stack<int> out;

  // run till stack is not empty
  while (!stk.empty()) {
    // we pop a node from the stack and push the data to output stack
    Node *curr = stk.top();
    stk.pop();

    out.push(curr->data);

    // push left and right child of popped node to the stack
    if (curr->left) stk.push(curr->left);

    if (curr->right) stk.push(curr->right);
  }

  // print post-order traversal
  while (!out.empty()) {
    cout << out.top() << " ";
    out.pop();
  }
}
