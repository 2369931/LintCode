#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

bool isIdentical(TreeNode * a, TreeNode * b) {
    if (a == NULL && b == NULL) {
        return true;
    }
    else if (a != NULL && b == NULL) {
        return false;
    }
    else if (a == NULL && b != NULL) {
        return false;
    }
    else {
        if (a->val == b->val) {
            return isIdentical(a->right,b->right) && isIdentical(a->left,b->left);
        }
        else {
            return false;
        }
    }
}


