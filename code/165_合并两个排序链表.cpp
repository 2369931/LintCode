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

ListNode * mergeTwoLists(ListNode * l1, ListNode * l2) {
    ListNode * l1_temp = l1;
    ListNode * l2_temp = l2;
    ListNode * result = new ListNode(0);
    ListNode * result_temp = result;
    if (l1 == NULL && l2 == NULL) return NULL;
    while (l1_temp != NULL && l2_temp != NULL) {
        if (l1_temp->val < l2_temp->val) {
            ListNode * temp = new ListNode(l1_temp->val);
            result_temp->next = temp;
            l1_temp = l1_temp->next;
            result_temp = result_temp->next;
        }
        else {
            ListNode * temp = new ListNode(l2_temp->val);
            result_temp->next = temp;
            l2_temp = l2_temp->next;
            result_temp = result_temp->next;
        }
    }
    if (l1_temp != NULL) {
        result_temp -> next = l1_temp;
    }
    else if (l2_temp != NULL) {
        result_temp -> next = l2_temp;
    }
    return result->next;
}
