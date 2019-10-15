#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <queue>

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

ListNode * swapNodes(ListNode * head, int v1, int v2) {
    if (head == NULL) {
        return head;
    }
    ListNode * new_head = new ListNode(-1);
    new_head -> next = head;
    ListNode * s = new_head;
    ListNode * p = new_head;
    ListNode * q = new_head;
    int a = 0;
    int flag_p = -1;
    int flag_q = -1;
    while (s->next != NULL) {
        if (s->next->val == v1) {
            p = s;
            flag_p = a;
        }
        else if (s->next->val == v2) {
            q = s;
            flag_q = a;
        }
        s = s->next;
        a ++;
    }
    if (flag_p != -1 && flag_q != -1 && flag_p != flag_q) {
        if (flag_p > flag_q) {
            ListNode * temp = p;
            p = q;
            q = temp;
        }
        if (abs(flag_q - flag_p) == 1) {
            ListNode * temp = q->next->next;
            q->next->next = p->next;
            p->next = q->next;
            q->next = temp;
            return new_head->next;
        }
        else {
            ListNode *temp_1 = q->next->next;
            q->next->next = p->next->next;
            p->next->next = temp_1;
            ListNode * temp_2 = q->next;
            q->next = p->next;
            p->next = temp_2;
            return new_head->next;
        }
    }
    return head;
}

int main() {
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(3);
    ListNode * c = new ListNode(2);
    ListNode * d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    ListNode * result = swapNodes(a,2,3);
    while(result != NULL) {
        cout << result -> val << " ";
        result = result->next;
    }
    return 0;
}
