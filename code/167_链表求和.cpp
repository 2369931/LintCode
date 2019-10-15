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

ListNode * addLists(ListNode * l1, ListNode * l2) {
    if (l1 == NULL) {
        return l2;
    }
    else if (l2 == NULL) {
        return l1;
    }
    ListNode * result = new ListNode(0);
    ListNode * l1_temp = l1;
    ListNode * l2_temp = l2;
    ListNode * result_temp = result;
    int flag = 0;
    while (l1_temp != NULL || l2_temp != NULL) {
        int sum = 0;
        if (l1_temp != NULL && l2_temp != NULL) {
            sum = l1_temp->val + l2_temp->val + flag;
        }
        else if (l1_temp != NULL && l2_temp == NULL) {
            sum = l1_temp->val + flag;
        }
        else if (l1_temp == NULL && l2_temp != NULL) {
            sum = l2_temp->val + flag;
        }
        if (sum >= 10) flag = 1;
        else flag = 0;
        ListNode * temp = new ListNode(sum%10);
        result_temp->next = temp;
        if (l1_temp != NULL)
            l1_temp = l1_temp->next;
        if (l2_temp != NULL)
            l2_temp = l2_temp->next;
        result_temp = result_temp->next;
    }
    if (flag == 1) {
        ListNode * temp = new ListNode(1);
        result_temp->next = temp;
    }
    return result->next;
}

