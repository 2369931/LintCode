
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

TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder) {
    int n = inorder.size();
    int m = postorder.size();
    if (n == 0 && m == 0) return NULL;
    TreeNode * root = new TreeNode(postorder[m-1]);
    if (n == 1 && m == 1) return root;
    int index = 0;
    for (int i = 0;i < inorder.size();i++) {
        if (inorder[i] == postorder[m-1]) {
            index = i;
            break;
        }
    }
    vector<int> inorder_left;
    vector<int> postorder_left;
    vector<int> inorder_right;
    vector<int> postorder_right;
    for (int i = 0; i < index; i++) {
        inorder_left.push_back(inorder[i]);
        postorder_left.push_back(postorder[i]);
    }
    for (int i = index + 1;i < n;i ++) {
        inorder_right.push_back(inorder[i]);
        postorder_right.push_back(postorder[i-1]);
    }
    root -> left = buildTree(inorder_left, postorder_left);
    root -> right = buildTree(inorder_right, postorder_right);
    return root;
}

};

int main() {
    return 0;
}
