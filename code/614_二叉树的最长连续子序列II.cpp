#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

class ReturnInfo {
public:
    int longest_up;
    int longest_down;
    ReturnInfo(int up, int down):longest_up(up), longest_down(down) {};
};

int longest = 0;

ReturnInfo longestInfo(TreeNode * root) {
    if (root == NULL) return ReturnInfo(0,0);
    int up = 1;
    int down = 1;
    ReturnInfo tempL = longestInfo(root->left);
    ReturnInfo tempR = longestInfo(root->right);

    if (root->left) {
        if (root->left->val == root->val - 1)
            up = max(up, tempL.longest_up+1);
        if (root->left->val == root->val + 1)
            down = max(down, tempL.longest_down+1);
    }
    if (root->right) {
        if (root->right->val == root->val - 1)
            up = max(up, tempR.longest_up+1);
        if (root->right->val == root->val + 1)
            down = max(down, tempR.longest_down+1);
    }
    longest = max(longest, up+down-1);
    return ReturnInfo(up,down);
}

int longestConsecutive2(TreeNode * root) {
    longestInfo(root);
    return longest;
}




