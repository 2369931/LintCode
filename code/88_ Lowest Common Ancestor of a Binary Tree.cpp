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

TreeNode * lowestCommonAncestor(TreeNode * root, TreeNode * A, TreeNode * B) {
    if (root == NULL) return NULL;
    if (root->val == A->val || root->val == B->val) return root;
    TreeNode * left =  lowestCommonAncestor(root->left,A,B);
    TreeNode * right =  lowestCommonAncestor(root->right,A,B);
    if (left != NULL && right != NULL) return root;
    else if (left != NULL && right == NULL) return left;
    else if (left == NULL && right != NULL) return right;
    else return NULL;
}

