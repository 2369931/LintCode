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

ListNode * middle(ListNode * head) {
    if (head == NULL) return NULL;
    ListNode * fast = head;
    ListNode * slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow -> next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode * mergeList(ListNode * left, ListNode * right) {
    if (left == NULL || right == NULL)
        return (left == NULL)?right:left;
    ListNode * head = new ListNode(0);
    ListNode * p = left;
    ListNode * q = right;
    ListNode * now = head;
    while (p != NULL && q != NULL) {
        if (p->val < q->val) {
            ListNode * temp = new ListNode(p->val);
            now -> next = temp;
            now = now -> next;
            p = p -> next;
        }
        else {
            ListNode * temp = new ListNode(q->val);
            now -> next = temp;
            now = now -> next;
            q = q->next;
        }
    }
    if (p != NULL) {
        now->next = p;
    }
    else if(q != NULL) {
        now->next = q;
    }
    return head->next;
}

ListNode * sortList(ListNode * head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * mid = middle(head);
    ListNode * right = sortList(mid->next);
    mid->next = NULL;
    ListNode * left = sortList(head);
    return mergeList(left,right);
}
