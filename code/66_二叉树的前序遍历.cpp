#include <iostream>
#include <vector>

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

void traversal (vector<int> &result, TreeNode * root) {
   if (root == NULL) return;
    else {
        result.push_back(root->val);
        traversal(result,root->left);
        traversal(result,root->right);
    }
}

vector<int> preorderTraversal(TreeNode * root) {
    vector<int> result;
    traversal (result, root);
    return result;
}

//·ÇµÝ¹é
vector<int> preorderTraversal(TreeNode * root) {
    vector<int> result;
    stack<TreeNode*> temp;
    if (root == NULL) return result;
    else {
        temp.push(root);
        while (!temp.empty()) {
            TreeNode * tree = temp.top();
            temp.pop();
            if (tree != NULL) {
                result.push_back(tree->val);
                temp.push(tree->right);
                temp.push(tree->left);
            }
        }
    }
    return result;
}

};

int main() {
    return 0;
}
