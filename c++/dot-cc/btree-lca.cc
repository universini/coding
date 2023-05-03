#include <iostream>

using namespace std;

struct node {
  node *left;
  node *right;
  int data;
};

class btree {
 public:
  btree() = default;
  ~btree() = default;

  node *get_node(int data) {
    node *n = new (node);
    if (!n) return nullptr;
    n->left = nullptr;
    n->right = nullptr;
    n->data = data;
    return n;
  }

  void insert_node(node **root, int data) {
    if (*root == nullptr) {
      *root = get_node(data);
    } else {
      if (data < (*root)->data) {
        insert_node(&(*root)->left, data);
      } else {
        insert_node(&(*root)->right, data);
      }
    }
  }

  void inorder_list(node *root) {
    if (root == nullptr) {
      return;
    } else {
      inorder_list(root->left);
      cout << root->data << " ";
      inorder_list(root->right);
    }
  }

  bool find_lca(node *root, node *n1, node *n2, node **lca) {
    bool ret1 = false, ret2 = false;

    if (root == nullptr) {
      return false;
    } else {
      if (root == n1 || root == n2) {
        *lca = root;
        return true;
      }
      ret1 = find_lca(root->left, n1, n2, lca);
      ret2 = find_lca(root->right, n1, n2, lca);
      if (ret1 && ret2) {
        *lca = root;
      }
    }

    return (ret1 || ret2);
  }
};

int main(void) {
  btree bt;
  node *root = nullptr;
  node *lca = nullptr;
  bool ret = false;
  /*
                10
            /      \
          6        14
        /   \     /    \
      4      8   12     18
  */
  bt.insert_node(&root, 10);
  bt.insert_node(&root, 6);
  bt.insert_node(&root, 4);
  bt.insert_node(&root, 8);
  bt.insert_node(&root, 14);
  bt.insert_node(&root, 12);
  bt.insert_node(&root, 18);

  cout << "Binary Tree Inorder List : ";
  bt.inorder_list(root);
  cout << endl;
  cout << " Lowest Common Ancestor : ";
  ret = bt.find_lca(root, root->left->right, root->right->left, &lca);
  if (ret) {
    cout << lca->data << endl;
  } else {
    cout << " LCA Doesn't Exist" << endl;
  }

  return 0;
}
