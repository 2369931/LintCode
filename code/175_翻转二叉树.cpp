#include <iostream>

using namespace std;

void invertBinaryTree(TreeNode * root) {
    if (root == NULL) return;
    else {
        TreeNode * temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }
}

int main() {
}
