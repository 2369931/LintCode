
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
//µÝ¹é
void traversal (vector<int> &result, TreeNode * root) {
   if (root == NULL) return;
    else {
        traversal(result,root->left);
        result.push_back(root->val);
        traversal(result,root->right);
    }
}

vector<int> sinorderTraversal(TreeNode * root) {
    vector<int> result;
    traversal (result, root);
    return result;
}

//·ÇµÝ¹é
vector<int> inorderTraversal(TreeNode * root) {
    vector<int> result;
    stack<TreeNode*> temp;
    if (root == NULL) return result;
    else {
        TreeNode * p = root;
        while (p != NULL || !temp.empty()) {
            while (p != NULL) {
                temp.push(p);
                p = p -> left;
            }
            if (!temp.empty()) {
                p = temp.top();
                result.push_back(p->val);
                temp.pop();
                if (p != NULL)
                    p = p -> right;
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
    vector<int> result = s.inorderTraversal(root);
    cout << result[0] << " " << result[1] << " " << result[2] << endl;
    return 0;
}
