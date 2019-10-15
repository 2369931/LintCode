

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

//Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:

TreeNode * buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = inorder.size();
    int m = preorder.size();
    if (n == 0 && m == 0) return NULL;
    TreeNode * root = new TreeNode(preorder[0]);
    if (n == 1 && m == 1) return root;
    int index = 0;
    for (int i = 0;i < inorder.size();i++) {
        if (inorder[i] == preorder[0]) {
            index = i;
            break;
        }
    }
    vector<int> inorder_left;
    vector<int> preorder_left;
    vector<int> inorder_right;
    vector<int> preorder_right;
    for (int i = 0; i < index; i++) {
        inorder_left.push_back(inorder[i]);
        preorder_left.push_back(preorder[i+1]);
    }
    for (int i = index + 1;i < n;i ++) {
        inorder_right.push_back(inorder[i]);
        preorder_right.push_back(preorder[i]);
    }
    root -> left = buildTree(preorder_left, inorder_left);
    root -> right = buildTree(preorder_right, inorder_right);
    return root;
}

};

int main() {
    return 0;
}
