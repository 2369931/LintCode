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


int highOfTree(TreeNode * root,int &flag) {
    if (root == NULL) {
        return 0;
    }
    int left = highOfTree(root->left,flag) + 1;
    int right = highOfTree(root->right,flag) + 1;
    if (abs(left-right) >= 2) {
        flag = 0;
    }
    return (left > right)?left:right;
}

bool isBalanced(TreeNode * root) {
    if (root == NULL) return true;
    int flag = 1;
    int left = highOfTree(root->left,flag);
    int right = highOfTree(root->right,flag);
    if (abs(left-right) < 2&&flag == 1) return true;
    return false;
}
