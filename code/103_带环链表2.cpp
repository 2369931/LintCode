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

ListNode * detectCycle(ListNode * head) {
    if (head == NULL || head->next == NULL) return NULL;
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (fast == NULL) return NULL;
    fast = head;
    while (slow != fast && fast != NULL &&slow != NULL) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
