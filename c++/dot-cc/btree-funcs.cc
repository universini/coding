#include <iostream>
#include <queue>

using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

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

  int find_min(node *root) {
    while (root->left) {
      root = root->left;
    }
    return root->data;
  }

  int find_max(node *root) {
    while (root->right) {
      root = root->right;
    }
    return root->data;
  }

  int num_nodes(node *root) {
    if (root == nullptr) {
      return 0;
    } else {
      return 1 + num_nodes(root->left) + num_nodes(root->right);
    }
  }

  int find_height(node *root) {
    if (root == nullptr) {
      return 0;
    } else {
      return 1 + MAX(find_height(root->left), find_height(root->right));
    }
  }

  node *find_successor(node *root) {
    while (root->left) {
      root = root->left;
    }
    return root;
  }

  node *delete_node(node *root, int data) {
    if (root == nullptr) {
      return nullptr;
    } else {
      if (data < root->data) {
        root->left = delete_node(root->left, data);
      } else if (data > root->data) {
        root->right = delete_node(root->right, data);
      } else {
        if (root->left == nullptr && root->right == nullptr) {
          delete root;
          return nullptr;
        } else if (root->left == nullptr) {
          node *temp = root;
          root = root->right;
          delete temp;
        } else if (root->right == nullptr) {
          node *temp = root;
          root = root->left;
          delete temp;
        } else {
          node *succ = find_successor(root->right);
          root->data = succ->data;
          root->right = delete_node(root->right, succ->data);
        }
      }
    }

    return root;
  }

  void level_print(node *root) {
    queue<node *> q;
    q.push(root);

    while (!q.empty()) {
      node *temp = q.front();
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

  void swap_nodes(node *root) {
    if (root == nullptr) {
      return;
    } else {
      node *temp = root->left;
      root->left = root->right;
      root->right = temp;
      swap_nodes(root->left);
      swap_nodes(root->right);
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

  cout << "Binary Tree Inorder List : ";
  bt.inorder_list(root);
  cout << endl;
  cout << "Min Element : " << bt.find_min(root) << endl;
  cout << "Max Element : " << bt.find_max(root) << endl;
  cout << "Number of Nodes : " << bt.num_nodes(root) << endl;
  cout << "Height of Tree : " << bt.find_height(root) << endl;
  bt.delete_node(root, 8);
  cout << "Binary Tree Inorder List (After Deleted 8) : ";
  bt.inorder_list(root);
  cout << endl;
  bt.level_print(root);
  bt.swap_nodes(root);
  bt.inorder_list(root);

  return 0;
}
