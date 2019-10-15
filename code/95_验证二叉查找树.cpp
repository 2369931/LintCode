#include <iostream>
#include <limits>
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
};
void find_valid(TreeNode * root,vector<int>& record) {
    if (root == NULL) return;
    find_valid(root->left,record);
    record.push_back(root->val);
    find_valid(root->right,record);
}
bool isValidBST(TreeNode * root) {
    if (root == NULL) return true;
    vector<int> record;
    find_valid(root,record);
    for (int i = 0;i < record.size()-1;i++) {
        if (record[i] >= record[i+1])
            return false;
    }
    return true;
}
