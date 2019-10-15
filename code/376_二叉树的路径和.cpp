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

void DFS(vector<vector<int> >& result, vector<int>& temp, int sum, int target, TreeNode * root) {
    if (root == NULL) return;
    sum += root->val;
    temp.push_back(root->val);
    if (sum == target && root->left == NULL && root->right == NULL) {
        result.push_back(temp);
        temp.pop_back();
        return;
    }
    else {
        if (root->left != NULL)
            DFS(result,temp,sum,target,root->left);
        if (root->right != NULL)
            DFS(result,temp,sum,target,root->right);
        temp.pop_back();
    }
}

vector<vector<int>> binaryTreePathSum(TreeNode * root, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    if (root == NULL) return result;
    DFS(result,temp,0,target,root);
    return result;
}

