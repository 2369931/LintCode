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

ListNode * removeElements(ListNode * head, int val) {
    if (head == NULL) {
        return NULL;
    }
    while (head != NULL && head->val == val) {
        ListNode * p = head;
        if (head != NULL) {
            head = head->next;
        }
        delete p;
        p = NULL;
    }
    if (head == NULL) {
        return NULL;
    }

    ListNode * node = head;
    while (node != NULL) {
        while (node->next != NULL && node->next->val == val) {
            ListNode * p = node;
            node->next = node->next->next;
            delete p;
            p = NULL;
        }
        node = node -> next;
    }
    return head;
}

int main() {
    ListNode * a = new ListNode(1);
    //ListNode * b = new ListNode(1);
    //ListNode * c = new ListNode(3);
    //ListNode * d = new ListNode(4);
    //ListNode * e = new ListNode(3);
    //a->next = b;
    //b->next = c;
    //c->next = d;
    //d->next = e;
    ListNode * head = removeElements(a,1);
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}

