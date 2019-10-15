#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
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
}

bool check(TreeNode * T1, TreeNode * T2) {
    if (T1 == NULL && T2 == NULL) return true;
    if (T1 == NULL || T2 == NULL) return false;
    if (T1->val == T2->val) {
        return check(T1->left, T2->left) && check(T1->right, T2->right);
    }
    else {
        return false;
    }
}


bool isSubtree(TreeNode * T1, TreeNode * T2) {
    if (T1 == NULL && T2 == NULL) return true;
    if (T1 != NULL && T2 == NULL) return true;
    if (T1 == NULL && T2 != NULL) return false;
    if (T1->val == T2->val) {
        if(check(T1, T2))
            return true;
    }
    if (isSubtree(T1->left, T2))
        return true;
    else if (isSubtree(T1->right, T2))
        return true;
    else return false;
}
