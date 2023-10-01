#include<iostream>

using namespace std;

typedef struct btree_node {
    int value;
    struct btree_node *left;
    struct btree_node *right;
} btree_node_t;

class btree {
    public:
        btree() = default;
        ~btree() = default;

        void insert_node(btree_node_t **root, int val)
        {
            if (*root == nullptr) *root = get_node(val);
            else {
                if (val < (*root)->value)
                    insert_node(&(*root)->left, val);
                else
                    insert_node(&(*root)->right, val);
            }
        }

        void print_inorder(btree_node_t *root)
        {
            if (root == nullptr) return;
            print_inorder(root->left);
            cout << root->value << " " << endl;
            print_inorder(root->right);
        }

        int return_closest(btree_node_t *root, int target)
        {
            int closest_num = root->value;
            int first_diff = std::abs(root->value - target);

            btree_node_t* current = root;

            while (current) {
                int next_diff = std::abs(current->value - target);
                if (next_diff < first_diff) {
                    first_diff = next_diff;
                    closest_num = current->value;
                }

                if (current->value == target) {
                    return current->value;
                } else if (current->value < target) {
                    current = current->right;
                } else {
                    current = current->left;
                }
            }

            return closest_num;
        }

    private:
        btree_node_t *get_node(int val)
        {
            btree_node_t *node = new btree_node_t;
            node->value = val;
            node->left = nullptr;
            node->right = nullptr;
            return node;
        }
};

int main(void)
{
    btree_node_t *root = nullptr;
    btree inst;

    inst.insert_node(&root, 10);
    inst.insert_node(&root, 5);
    inst.insert_node(&root, 23);
    inst.insert_node(&root, 8);
    inst.insert_node(&root, 12);
    inst.insert_node(&root, 3);

    inst.print_inorder(root);
    cout << "Closest to 15 is " << inst.return_closest(root, 15) << endl;
    return 0;
}