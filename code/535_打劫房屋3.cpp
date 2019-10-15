#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>

using namespace std;

vector<int> record(TreeNode * root) {
    if (root == NULL) {
        return {0,0};
    }
    vector<int> left = record(root->left);
    vector<int> right = record(root->right);
    vector<int> res = {0,0};
    res[0] = max(left[0],left[1]) + max(right[0],right[1]);
    res[1] = root->val + left[0] + right[0];
    return res;
}

int houseRobber3(TreeNode * root) {
    vector<int> res = record(root);
    return max(res[0],res[1]);
}
