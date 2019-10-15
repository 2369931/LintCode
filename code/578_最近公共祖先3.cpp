#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

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

bool find_node(TreeNode * root, TreeNode * A) {
    if (root == NULL || A == NULL) {
        return false;
    }
    else if (root->val == A->val) {
        return true;
    }
    else if (find_node(root->left,A) || find_node(root->right,A)){
        return true;
    }
    return false;
}

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

TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
    if (root == NULL || !find_node(root,A) || !find_node(root,B)) return NULL;
    else return lowestCommonAncestor(root,A,B);
}
