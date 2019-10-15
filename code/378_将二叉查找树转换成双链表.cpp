#include <iostream>
#include <vector>

using namespace std;

class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int val) {
        this->val = val;
        this->prev = this->next = NULL;
    }
};

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

void generate(vector<int>& record, TreeNode * root) {
    if (root == NULL) return;
    generate(record, root->right);
    record.insert(record.begin(), root->val);
    generate(record, root->left);
}

DoublyListNode * bstToDoublyList(TreeNode * root) {
    if (root == NULL) return NULL;
    vector<int> record;
    generate (record, root);
    DoublyListNode * result = new DoublyListNode(record[0]);
    DoublyListNode * temp = result;
    for (int i = 1;i < record.size();i++) {
        DoublyListNode * node = new DoublyListNode(record[i]);
        temp->next = node;
        node->prev = temp;
        temp = temp->next;
    }
    return result;
}
