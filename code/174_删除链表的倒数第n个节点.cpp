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

ListNode * removeNthFromEnd(ListNode * head, int n) {
    if (head == NULL) return NULL;
    ListNode * slow = head;
    ListNode * pre_slow = head;
    ListNode * fast = head;
    int flag = 0;
    for (int i = 0;i < n;i++) {
        fast = fast->next;
    }
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
        if (flag == 0) {
            flag = 1;
            continue;
        }
        pre_slow = pre_slow->next;
    }
    if (pre_slow == head) {
        return head->next;
    }
    else if (pre_slow->next != NULL)
        pre_slow->next = pre_slow->next->next;
    else {
        return NULL;
    }
    return head;
}


