#include <iostream>
#include <stack>

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

  void zizag_print(node *root) {
    bool left2right = true;
    stack<node *> s1;
    stack<node *> s2;

    if (root == nullptr) {
      return;
    }

    s1.push(root);

    while (!s1.empty()) {
      node *temp = s1.top();
      s1.pop();
      cout << temp->data << " ";

      if (left2right) {
        if (temp->left != nullptr) {
          s2.push(temp->left);
        }
        if (temp->right != nullptr) {
          s2.push(temp->right);
        }
      } else {
        if (temp->right != nullptr) {
          s2.push(temp->right);
        }
        if (temp->left != nullptr) {
          s2.push(temp->left);
        }
      }

      if (s1.empty()) {
        left2right = !left2right;
        swap(s1, s2);
      }
    }
  }
};

int main(void) {
  btree bt;
  node *root = nullptr;
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

  cout << "Binary Tree in ZigZag Inorder : ";
  bt.zizag_print(root);
  cout << endl;

  return 0;
}
