#include <iostream>

using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
        this->val = val;
        this->next = NULL;
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

ListNode * middle(ListNode * head) {
    if (head == NULL) return head;
    ListNode * fast = head -> next -> next;
    ListNode * slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

TreeNode * sortedListToBST(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        TreeNode * temp = new TreeNode(head->val);
        return temp;
    }
    ListNode * mid = middle(head);
    TreeNode * root = new TreeNode(mid->next->val);
    ListNode * left = head;
    ListNode * right = mid->next->next;
    mid->next = NULL;
    root->left = sortedListToBST(left);
    root->right = sortedListToBST(right);
    return root;
}
