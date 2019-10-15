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

void mid(vector<int> &result,TreeNode * root,int k1, int k2) {
    if (root == NULL) {
        return;
    }
    mid(result,root->left,k1,k2);
    if (root->val >= k1 && root->val <= k2)
        result.push_back(root->val);
    mid(result,root->right,k1,k2);
}

vector<int> searchRange(TreeNode * root, int k1, int k2) {
    vector <int> result;
    mid(result,root,k1,k2);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(20);
    TreeNode left(8);
    root->left = &left;
    TreeNode right(22);
    root->right = &right;
    TreeNode left1(4);
    TreeNode right1(12);
    root->left->left = &left1;
    root->left->right = &right1;
    //vector<int> result = searchRange(root,10,22);
    vector<int> result;
    mid(result,root,10,22);
    for (int i = 0;i < result.size();i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
