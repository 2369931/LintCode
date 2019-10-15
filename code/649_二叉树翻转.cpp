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

TreeNode * upsideDownBinaryTree(TreeNode * root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    TreeNode * new_root = upsideDownBinaryTree(root->left);
    root->left->left = root->right;
    root->left->right = root;
    root->left = NULL;
    root->right = NULL;
    return new_root;
}
