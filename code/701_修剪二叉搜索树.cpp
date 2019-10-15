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
}

TreeNode * trimBST(TreeNode * root, int minimum, int maximum) {
    if (!root) {
        return NULL;
    }
    if (root->val < minimum) {
        return trimBST(root->right, minimum, maximum);
    }
    if (root->val > maximum) {
        return trimBST(root->left, minimum, maximum);
    }
    root->left = trimBST(root->left, minimum, maximum);
    root->right = trimBST(root->right, minimum, maximum);
    return root;
}

