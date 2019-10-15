#include <iostream>
#include <map>

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

map<TreeNode*, int> record;

void helper(TreeNode * root) {
    if (!root) {
        return;
    }
    if (root->left) {
        if (root->left->val == root->val + 1) {
            record[root->left] = record[root] + 1;
        }
        else {
            record[root->left] = 1;
        }
        helper(root->left);
    }
    if (root->right) {
        if (root->right->val == root->val + 1) {
            record[root->right] = record[root] + 1;
        }
        else {
            record[root->right] = 1;
        }
        helper(root->right);
    }
}

int longestConsecutive(TreeNode * root) {
    if (!root) {
        return 0;
    }
    int result = 0;
    record[root] = 1;
    helper(root);
    for (map<TreeNode*,int>::iterator it = record.begin();it != record.end();it++) {
        result = max(result,it->second);
    }
    return result;
}
