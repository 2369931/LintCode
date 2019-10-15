#include <iostream>
#include <stack>

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

TreeNode * removeNode(TreeNode * root, int value){
    if (root == NULL) return root;
    if (root->val > value) {
        root->left = removeNode(root->left, value);
    }
    else if (root->val < value) {
        root->right = removeNode(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) root = NULL;
        else if (root->left != NULL && root->right == NULL) root = root->left;
        else if (root->left == NULL && root->right != NULL) root = root->right;
        else {
            TreeNode * p = root->right;
            while (p->left != NULL) {
                p = p->left;
            }
            root->val = p->val;
            root->right = removeNode(root->right,p->val);
        }
    }
    return root;
}
