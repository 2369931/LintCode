#include <iostream>
#include <vector>
#include <cmath>

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

void flatten(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    ConvertToLink(root);
}

TreeNode * ConvertToLink(TreeNode * root) {
    if (root == NULL) {
        return root;
    }
    TreeNode * leftLinkTail = ConvertToLink(root->left);
    TreeNode * rightLinkTail = ConvertToLink(root->right);
    if (leftLinkTail != NULL) {
        leftLinkTail->right = root->right;
        root->right = root->left;
    }

    root->left = NULL;
    if (rightLinkTail != NULL) {
        return rightLinkTail;
    }
    else if (leftLinkTail != NULL) {
        return leftLinkTail;
    }
    else
        return root;
}
