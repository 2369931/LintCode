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
}

ListNode * nthToLast(ListNode * head, int n) {
    if (head == NULL) return NULL;
    ListNode * slow = head;
    ListNode * fast = head;
    for (int i = 0;i < n;i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

