#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode * temp = NULL;

void find_next(TreeNode * root, int value) {
    if (root->val > value) {
        temp = root;
        find_next(root->left,value);
    }
    else if (root->val < value) {
        find_next(root->right,value);
    }
    else
        return;
}

TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
    if (root == NULL || p == NULL) {
        return NULL;
    }
    if (p->right) {
        if (p->right->left) {
            TreeNode * temp = p->right->left;
            while (temp->left) {
                temp = temp->left;
            }
            return temp;
        }
        else {
            return p->right;
        }
    }
    else {
        find_next(root,p->val);
        return temp;
    }
}
