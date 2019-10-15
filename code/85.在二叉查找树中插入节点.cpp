#include <iostream>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void insert_node(TreeNode * root, TreeNode * node) {
    if (node->val >= root->val) {
        if (root->right == NULL) {
            root->right = node;
            return;
        }
        else {
            insert_node(root->right,node);
        }
    }
    else {
        if (root->left == NULL) {
            root->left = node;
            return;
        }
        else {
            insert_node(root->left,node);
        }
    }
}

TreeNode * insertNode(TreeNode * root, TreeNode * node) {
        if (root == NULL) return node;
        insert_node(root,node);
        return root;
}
