#include <iostream>
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
};


int maxDepth(TreeNode * root) {
    if (root == NULL) return 0;
    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;
    return max(left,right);
}
