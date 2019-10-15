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
};

void pre_order_1(TreeNode * root) {
    if (root != NULL) {
        cout << root->val << " ";
        pre_order_1(root->left);
        pre_order_1(root->right);
    }
}

TreeNode * help (vector<int> &temp, TreeNode * root) {
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL) {
        temp.push_back(root->val);
        return NULL;
    }
    root->left = help(temp,root->left);
    root->right = help(temp,root->right);
}

vector<vector<int> > findLeaves(TreeNode * root) {
    vector<vector<int> > result;
    if (root == NULL) {
        return result;
    }
    while (root) {
        vector<int> temp;
        root = help(temp,root);
        result.push_back(temp);
    }
    return result;
}

int main() {
    TreeNode * root = new TreeNode(1);
    TreeNode * a = new TreeNode(2);
    TreeNode * b = new TreeNode(3);
    TreeNode * c = new TreeNode(4);
    TreeNode * d = new TreeNode(5);
    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    vector<int> temp;
    pre_order_1(root);
    cout << endl;
    help(temp,root);
    pre_order_1(root);
    cout << endl;
    //vector<vector<int> > result = findLeaves(root);
    return 0;
}
