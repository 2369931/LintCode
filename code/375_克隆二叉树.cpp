#include <iostream>
#include <vector>

using namespace std;

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
}

TreeNode * cloneTree(TreeNode * root) {
    if (root == NULL) return NULL;
    TreeNode * node = new TreeNode(root->val);
    node->left = cloneTree(root->left);
    node->right = cloneTree(root->right);
    return node;
}
