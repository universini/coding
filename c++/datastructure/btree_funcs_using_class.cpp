#include <iostream>
#include <queue>

using namespace std;

typedef struct btree_s {
  struct btree_s *left, *right;
  int data;
} btree_t;

void print_btree(btree_t *root) {
  btree_t *t = root;

  if (!t)
    return;
  else {
    print_btree(t->left);
    cout << t->data << " ";
    print_btree(t->right);
  }
}

btree_t *insert_btree(btree_t *root, int data) {
  if (root == NULL) {
    root = new btree_t;
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

#define MAX(a, b) (a) > (b) ? (a) : (b)

int height_btree(btree_t *root) {
  if (!root)
    return (-1);
  else {
    int lheight = height_btree(root->left);
    int rheight = height_btree(root->right);

    return ((lheight > rheight) ? lheight + 1 : rheight + 1);
  }
}

btree_t *find_max(btree_t *root) {
  if (!root)
    return (root);
  else {
    while (root->right) root = root->right;
  }

  return (root);
}

btree_t *find_min(btree_t *root) {
  if (!root)
    return (root);
  else {
    while (root->left) root = root->left;
  }

  return (root);
}

int num_nodes(btree_t *root) {
  if (root == nullptr) {
    return 0;
  } else {
    return 1 + num_nodes(root->left) + num_nodes(root->right);
  }
}

void swap_btree(btree_t *root) {
  btree_t *temp;

  if (!root) return;

  temp = root->left;
  root->left = root->right;
  root->right = temp;

  swap_btree(root->left);
  swap_btree(root->right);
}

btree_t *create_btree_node(int data) {
  btree_t *node = new btree_t;

  node->data = data;
  node->left = node->right = NULL;

  return (node);
}

btree_t *clone_node(btree_t *node) {
  btree_t *newn = new btree_t;

  newn->data = node->data;
  newn->left = newn->right = NULL;

  return (newn);
}

btree_t *clone_btree(btree_t *root) {
  btree_t *newn;

  if (!root)
    return (root);
  else {
    newn = clone_node(root);
    newn->left = clone_btree(root->left);
    newn->right = clone_btree(root->right);
  }

  return (newn);
}

void find_successor(btree_t *root, btree_t *&succ, int key) {
  if (!root) {
    succ = NULL;
    return;
  }

  if (root->data == key) {
    if (root->right) {
      succ = find_min(root->right);
    }

    return;
  }

  if (root->data < key) {
    find_successor(root->left, succ, key);
  } else {
    succ = root;
    find_successor(root->right, succ, key);
  }
}

void inorder_successor(btree_t *root, int key) {
  btree_t *succ = NULL;

  find_successor(root, succ, key);

  if (succ) {
    cout << "\nSuccessor of " << key << " is " << succ->data << endl;
  } else {
    cout << "\nSuccessor wasn't found" << endl;
  }
}

void find_predecessor(btree_t *root, btree_t *&pred, int key) {
  if (!root) {
    pred = NULL;
    return;
  }

  if (root->data == key) {
    if (root->left) {
      pred = find_max(root->left);
    }

    return;
  }

  if (root->data < key) {
    pred = root;
    find_predecessor(root->left, pred, key);
  } else {
    find_predecessor(root->right, pred, key);
  }
}

void inorder_predecessor(btree_t *root, int key) {
  btree_t *pred = NULL;

  find_predecessor(root, pred, key);

  if (pred) {
    cout << "\nPredecessor of " << key << " is " << pred->data << endl;
  } else {
    cout << "\nPredecessor wasn't found" << endl;
  }
}

bool ancestors_btree(btree_t *root, int num) {
  if (!root) return false;

  if (root->data == num) return true;

  bool left = ancestors_btree(root->left, num);
  bool right = ancestors_btree(root->right, num);

  if (left || right) cout << root->data << " ";

  return (left || right);
}

int range_sum_btree(btree_t *root, int num1, int num2) {
  static int sum = 0;

  if (!root)
    return (0);
  else {
    if (root->data >= num1 && root->data <= num2) {
      sum = sum + root->data;
    }

    range_sum_btree(root->left, num1, num2);
    range_sum_btree(root->right, num1, num2);
  }

  return (sum);
}

void level_print(btree_t *root) {
  queue<btree_t *> q;
  q.push(root);

  while (!q.empty()) {
    btree_t *temp = q.front();
    q.pop();
    cout << temp->data << endl;
    if (temp->left != nullptr) {
      q.push(temp->left);
    }

    if (temp->right != nullptr) {
      q.push(temp->right);
    }
  }
}

btree_t *range_del_btree(btree_t *root, int num1, int num2) {
  if (!root) return NULL;

  root->left = range_del_btree(root->left, num1, num2);
  root->right = range_del_btree(root->right, num1, num2);

  btree_t *temp = root;

  if (root->data < num1) {
    root = root->right;
    delete temp;
  }

  if (root->data > num2) {
    root = root->left;
    delete temp;
  }

  return (root);
}

bool are_trees_identical(btree_t *t1, btree_t *t2) {
  if (!t1 && !t2) return true;

  return (t1 && t1) && (t1->data == t2->data) &&
         are_trees_identical(t1->left, t2->left) &&
         are_trees_identical(t1->right, t2->right);
}

void double_btree(btree_t *root) {
  btree_t *temp;

  if (!root) return;

  double_btree(root->left);
  double_btree(root->right);

  temp = root->left;
  root->left = clone_node(root);
  root->left->left = temp;
}

int diameter_btree(btree_t *root) {
  int lheight, rheight, lwidth, rwidth;

  if (!root)
    return (0);
  else {
    lheight = height_btree(root->left);
    rheight = height_btree(root->right);
    int height = lheight + rheight + 1;

    lwidth = diameter_btree(root->left);
    rwidth = diameter_btree(root->right);

    int width = (lwidth > rwidth) ? lwidth : rwidth;

    return (MAX(height, width));
    // or
    // return(MAX(lheight+rheight+1, MAX(lwidth, rwidth)));
  }
}

btree_t *create_bst_from_array(int a[], int min, int max) {
  btree_t *root;

  if (min > max) return (NULL);

  int mid = (min + max) / 2;

  root = create_btree_node(a[mid]);
  root->left = create_bst_from_array(a, min, mid - 1);
  root->right = create_bst_from_array(a, mid + 1, max);

  return (root);
}

btree_t *delete_btree(btree_t *root, btree_t *node) {
  if (!root) return (root);

  if (node->data < root->data) {
    root->left = delete_btree(root->left, node);
  } else if (node->data > root->data) {
    root->right = delete_btree(root->right, node);
  } else {
    // no child case
    if (root->left == NULL && root->right == NULL) {
      delete (root);
      root = NULL;
    } else if (root->left == NULL) {
      // no left-child case
      btree_t *temp = root;
      root = root->right;
      delete (temp);
    } else if (root->right == NULL) {
      // no right-child case
      btree_t *temp = root;
      root = root->left;
      delete (temp);
    } else {
      // both children case
      btree_t *temp = find_min(root->right);
      root->data = temp->data;
      root->right = delete_btree(root->right, temp);
    }
  }

  return (root);
}

int main(void) {
  btree_t *root = NULL, *nroot;
  int a[] = {1, 2, 3, 4, 5};

  root = insert_btree(root, 15);
  root = insert_btree(root, 12);
  root = insert_btree(root, 25);
  root = insert_btree(root, 37);
  root = insert_btree(root, 18);
  root = insert_btree(root, 9);
  root = insert_btree(root, 16);

  print_btree(root);
  cout << "\n";
  inorder_predecessor(root, 15);
  inorder_successor(root, 15);

  cout << "\nAfter deleting " << root->right->data << endl;
  root = delete_btree(root, root->right);
  print_btree(root);

  cout << "\nHeight of tree is " << height_btree(root) << endl;

  swap_btree(root);
  print_btree(root);

  cout << "\nDiameter of tree is " << diameter_btree(root) << endl;

  cout << "\nBTree from array" << endl;
  nroot = create_bst_from_array(a, 0, 4);
  print_btree(nroot);

  cout << "\nRange sum from 2 to 4 is " << range_sum_btree(nroot, 2, 4) << endl;

  cout << "\nAncestor of 4" << endl;
  cout << ancestors_btree(nroot, 2) << endl;

  cout << "Are trees identical?" << endl;
  cout << are_trees_identical(root, nroot) << endl;
  // nroot = range_del_btree(nroot, 3, 4);
  // print_btree(nroot);

  cout << "\nDouble tree" << endl;
  double_btree(root);
  print_btree(root);

  cout << "\nCloned tree" << endl;
  nroot = clone_btree(root);
  print_btree(nroot);
  cout << endl;
  return (0);
}
