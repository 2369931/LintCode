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

TreeNode * largest = new TreeNode(INT_MIN);

void max_Node(TreeNode * root) {
    if (root != NULL) {
        if (root->val > largest->val) {
            largest = root;
        }
        max_Node(root->left);
        max_Node(root->right);
    }
}

TreeNode * maxNode(TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }
    max_Node(root);
    return largest;
}

