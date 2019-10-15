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

ListNode * rotateRight(ListNode * head, int k) {
    if (head == NULL) return NULL;
    int length = 0;
    ListNode * length_head = head;
    while (length_head != NULL) {
        length ++;
        length_head = length_head->next;
    }
    k = k % length;
    if (k == 0) return head;
    ListNode * head_temp = head;
    ListNode * new_head = head;
    for (int i = 0;i < length - k;i ++) {
        new_head = new_head->next;
    }
    for (int i = 0;i < length - k - 1;i ++) {
        head_temp = head_temp->next;
    }
    ListNode * new_head_temp = new_head;
    while (new_head_temp->next != NULL) {
        new_head_temp = new_head_temp->next;
    }
    head_temp->next = NULL;
    new_head_temp->next = head;
    return new_head;
}

