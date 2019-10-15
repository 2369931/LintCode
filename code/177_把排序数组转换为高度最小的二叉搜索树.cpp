#include <iostream>

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

TreeNode * dp(vector<int> &A, int left, int right) {
    if (left > right) return NULL;
    int index = (left + right)/2;
    TreeNode * root = new TreeNode(A[index]);
    root->left = dp(A,left,index-1);
    root->right = dp(A,index+1,right);
    return root;
}

TreeNode * sortedArrayToBST(vector<int> &A) {
    int n = A.size();
    if (n == 0) return NULL;
    int mid = (n-1)/2;
    TreeNode * root = new TreeNode(A[mid]);
    root->left = dp(A,0,mid-1);
    root->right = dp(A,mid+1,A.size()-1);
    return root;
}

int main() {
}

