#include <iostream>
#include <limits>

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

int find_max(TreeNode * root,int &Max) {
   if (root == NULL) return 0;
   int left =  find_max(root->left,Max);
   int right = find_max(root->right,Max);
   Max = max((max(0,left) + max(0,right) + root->val),Max);
   return max(left,right) + root->val;

}

int maxPathSum(TreeNode * root) {
    int Max = INT_MIN;
    find_max(root,Max);
    return Max;
}
