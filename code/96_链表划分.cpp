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

ListNode * partition(ListNode * head, int x) {
    if (head == NULL) return NULL;
    ListNode* p = new ListNode(0);
    ListNode* q = new ListNode(0);
    ListNode* p_head = p;
    ListNode* q_head = q;
    while (head != NULL) {
        ListNode * node = new ListNode(head->val);
        if (head->val >= x) {
            p->next = node;
            p = p->next;
        }
        else {
            q->next = node;
            q = q->next;
        }
        head = head->next;
    }
    q->next = p_head->next;
    return q_head->next;
}
