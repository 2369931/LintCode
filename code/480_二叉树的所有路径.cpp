#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <sstream>

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

string IntToString(int a) {
    stringstream ss;
    ss << a;
    string s = "";
    ss >> s;
    return s;
}

void find_paths(vector<string> &result, string &path, TreeNode *root) {
    if (root->left == NULL && root->right == NULL) {
        result.push_back(path);
    }
    else {
        string left = "";
        string right = "";
        if (root->left != NULL) {
            left = path + "->" + IntToString(root->left->val);
            find_paths(result,left,root->left);
        }
        if (root->right != NULL) {
            right = path + "->" + IntToString(root->right->val);
            find_paths(result,right,root->right);
        }
    }
}

vector<string> binaryTreePaths(TreeNode * root) {
    vector<string> result;
    if (root == NULL) {
        return result;
    }
    string path = IntToString(root->val);
    find_paths(result,path,root);
    return result;
}
