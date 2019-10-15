

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

//·ÇµÝ¹é
vector<int> postorderTraversal(TreeNode * root) {
    vector<int> result;
    stack<TreeNode*> s;
    if (root == NULL) return result;
    TreeNode * cur = root;
    TreeNode * pre = NULL;
    s.push(root);
    while (!s.empty()) {
        cur = s.top();
        if ((cur->left == NULL && cur->right == NULL) ||
            (pre != NULL && (pre == cur -> left || pre == cur -> right))) {
                result.push_back(cur->val);
                s.pop();
                pre = cur;
            }
        else {
            if (cur->right != NULL) {
                s.push(cur->right);
            }
            if (cur->left != NULL) {
                s.push(cur->left);
            }
        }
    }
    return result;
}

};

int main() {
    TreeNode * root = new TreeNode(1);
    TreeNode * left = new TreeNode(2);
    TreeNode * right = new TreeNode(3);
    root -> left = left;
    root -> right = right;
    Solution s;
    vector<int> result = s.postorderTraversal(root);
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}
