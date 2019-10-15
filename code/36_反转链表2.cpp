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

ListNode* reverse(ListNode * head) {
    if (head == NULL) {
        return NULL;
    }
    else if (head -> next == NULL) {
        return head;
    }
    else {
        ListNode * p = head;
        ListNode * q = NULL;
        while (p != NULL) {
            ListNode * temp = p -> next;
            p -> next = q;
            q = p;
            p = temp;
        }
        return q;
    }
}

ListNode * reverseBetween(ListNode * head, int m, int n) {
    if (m == n || head->next == NULL) {
        return head;
    }
    ListNode * pre = new ListNode(0);
    pre -> next = head;
    ListNode * new_head = pre;
    ListNode * s;
    ListNode * e;
    for (int i = 1;i < n;i ++){
        if (i == m - 1) new_head = head;
        head = head -> next;
    }
    s = new_head -> next;
    e = head;
    ListNode * tail = e -> next;
    e -> next = NULL;
    reverse(s);
    new_head -> next = e;
    s -> next = tail;
    return pre->next;
}

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    ListNode * head = reverseBetween(a,3,4);
    while (head != NULL) {
        cout << head -> val << endl;
        head = head -> next;
    }
    return 0;
}
