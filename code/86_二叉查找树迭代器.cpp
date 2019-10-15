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


class BSTIterator {
public:
    stack<TreeNode*> record;
    /*
    * @param root: The root of binary tree.
    */BSTIterator(TreeNode * root) {
        if (root != NULL) {
            record.push(root);
            TreeNode* p = root;
            while (p->left != NULL) {
                record.push(p->left);
                p = p->left;
            }
        }
    }
    /*
     * @return: True if there has next node, or false
     */
    bool hasNext() {
        // write your code here
        return !record.empty();
    }

    /*
     * @return: return next node
     */
    TreeNode * next() {
        // write your code here
        TreeNode * temp = record.top();
        record.pop();
        if (temp->right != NULL) {
            TreeNode * right = temp->right;
            record.push(right);
            while (right->left != NULL) {
                record.push(right->left);
                right = right->left;
            }
        }
        return temp;
    }
};

int main() {
    return 0;
}
