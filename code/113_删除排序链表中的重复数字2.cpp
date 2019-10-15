#include <iostream>
#include <cmath>
#include <limits>
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

ListNode * deleteDuplicates(ListNode * head) {
    if (head == NULL || head -> next == NULL) return head;
    ListNode * temp = head;
    ListNode * temp_next = temp -> next;
    while (temp_next != NULL) {
        int value = temp -> val;
        int temp_value = temp_next -> val;
        if (value == temp_value) {
            temp -> next = temp_next -> next;
            temp_next = temp_next -> next;
        }
        else {
            temp = temp_next;
            temp_next = temp_next -> next;
        }
    }
    return head;
}
ListNode * deleteDuplicates(ListNode * head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * result = new ListNode(0);
    ListNode * t = result;
    ListNode * l = head;
    ListNode * p = head;
    ListNode * q = head -> next;
    while (p != NULL) {
        int value = -999999;
        if (p == head) {
            if (p->val != q->val) {
                value = p->val;
            }
        }
        else {
            if ((l->val != p->val &&  q == NULL) || (l->val != p->val && p->val != q->val)){
                value = p->val;
            }
        }
        if (value != -999999) {
            ListNode * temp = new ListNode(value);
            t -> next = temp;
            t = t -> next;
        }
        l = p;
        p = p -> next;
        if (q != NULL)
            q = q -> next;
    }
    return result -> next;
}

int main() {
    return 0;
}

