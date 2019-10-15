#include <iostream>
#include <vector>

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

ListNode * getIntersectionNode(ListNode * headA, ListNode * headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    ListNode * p = headA;
    ListNode * q = headB;
    int len_a = 0;
    int len_b = 0;
    while (p != NULL) {
        p = p -> next;
        len_a ++;
    }
    while (q != NULL) {
        q = q -> next;
        len_b ++;
    }
    if (len_a > len_b) {
        while (len_a > len_b) {
            headA = headA -> next;
            len_a --;
        }
    }
    else {
        while (len_b > len_a) {
            headB = headB -> next;
            len_b --;
        }
    }
    while (headA != NULL && headB != NULL) {
        if (headA == headB) {
            return headA;
        }
        headA = headA -> next;
        headB = headB -> next;
    }
    return NULL;
}
