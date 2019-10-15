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

vector<TreeNode *> dp(int start, int end) {
    vector<TreeNode *> ret;
    if (start > end) {
        ret.push_back(NULL);
    }
    else if (start == end) {
        TreeNode* temp = new TreeNode(start);
        ret.push_back(temp);
    }
    else {
        for (int i = start;i <= end;i++) {
            vector<TreeNode*> left = dp(start, i-1);
            vector<TreeNode*> right = dp(i+1, end);
            for (int j = 0;j < left.size();j++) {
                for (int k = 0;k < right.size();k++) {
                    TreeNode* temp = new TreeNode(i);
                    temp->left = left[j];
                    temp->right = right[k];
                    ret.push_back(temp);
                }
            }

        }
    }
    return ret;
}

vector<TreeNode *> generateTrees(int n) {
    vector<TreeNode*> result = dp(1,n);
    return result;
}

