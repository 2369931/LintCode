#include <iostream>
#include <vector>
#include <cmath>

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

ListNode * reverseKGroup(ListNode * head, int k) {
    if (head == NULL) {
        return NULL;
    }
    if (k == 1) {
        return head;
    }
    int length = 0;
    ListNode * node = head;
    ListNode * prev = NULL;
    ListNode * next = NULL;
    ListNode * p = NULL;
    ListNode * q = NULL;
    int flag = 1;
    while (node != NULL) {
        q = node;
        ListNode * record = node;
        int i = 0;
        while (i < k) {
            if (node != NULL) {
                node = node->next;
            }
            else {
                return head;
            }
            i ++;
        }
        next = node;
        p = next;
        while (q != next) {
            ListNode * temp = q->next;
            q->next = p;
            p = q;
            q = temp;
        }
        if (prev != NULL)
            prev->next = p;
        prev = record;
        if (flag == 1) {
            head = p;
            flag = 0;
        }
    }
    return head;
}

int main() {
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    ListNode * d = new ListNode(4);
    ListNode * e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    ListNode * head = reverseKGroup(a,5);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}
