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

TreeNode * pre = NULL;
TreeNode * p1 = NULL;
TreeNode * p2 = NULL;

void inOrder(TreeNode * root) {
    if (!root) {
        return;
    }
    inOrder(root->left);
    if (pre != NULL && pre->val > root->val) {
        if (p1 == NULL) {
            p1 = pre;
        }
        p2 = root;
    }
    pre = root;
    inOrder(root->right);
}

TreeNode * bstSwappedNode(TreeNode * root) {
    if (!root) {
        return root;
    }
    inOrder(root);
    if (p1 != NULL && p2 != NULL) {
        int temp = p1->val;
        p1->val = p2->val;
        p2->val = temp;
    }
    return root;
}
