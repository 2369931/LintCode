#include <iostream>
#include <queue>
#include <limits>

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

int minDepth(TreeNode * root) {
    if (root == NULL) return 0;
    if (root->left == NULL ) {
        return minDepth(root->right)+1;
    }
    else if (root->right == NULL) {
        return minDepth(root->left)+1;
    }
    int leftDepth = minDepth(root->left)+1;
    int rightDepth = minDepth(root->right)+1;
    return leftDepth < rightDepth ? (leftDepth) : (rightDepth);
}
