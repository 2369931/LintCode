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

/*void mid_order(TreeNode * root,vector<int> &result) {
    if (root != NULL) {
        mid_order(root->left,result);
        result.push_back(root->val);
        mid_order(root->right,result);
    }
}

void convert(TreeNode * root, map<int,int> record) {
    if (root != NULL) {
        convert(root->left,record);
        root->val = record[root->val];
        convert(root->right,record);
    }
}

TreeNode * convertBST(TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }
    vector<int> result;
    map<int,int> record;
    mid_order(root,result);
    int sum = 0;
    for (int i = result.size()-1;i >= 0;i--) {
        record[result[i]] = result[i] + sum;
        sum += result[i];
    }
    convert(root,record);
    return root;
}*/

int sum = 0;

TreeNode * convertBST(TreeNode * root) {
    if (root == NULL) {
        return NULL;
    }
    convertBST(root->right);
    sum += root->val;
    root->val = sum;
    convertBST(root->left);
    return root;
}
