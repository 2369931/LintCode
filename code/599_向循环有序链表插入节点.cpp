#include <iostream>
#include <vector>
#include <algorithm>

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

ListNode * insert(ListNode * node, int x) {
    ListNode * temp = new ListNode(x);
    if (node == NULL) {
        temp->next = temp;
        return temp;
    }
    else {
        ListNode * head = node;
        if (head->next == head) {
            head->next = temp;
            temp->next = head;
            return node;
        }
        int flag = 0;
        int value = 0;
        ListNode * tail = NULL;
        while (flag != 1) {
            if (head->val <= x && head->next->val >= x) {
                ListNode * temp_next = head->next;
                head->next = temp;
                temp->next = temp_next;
                return node;
            }
            if (head->val >= value) {
                tail = head;
                value = head->val;
            }
            head = head->next;
            if (head == node) {
                flag = 1;
            }
        }
        ListNode * temp_tail = tail->next;
        tail->next = temp;
        temp->next = temp_tail;
        return node;
    }
}

int main() {
    ListNode * a = new ListNode(3);
    ListNode * b = new ListNode(5);
    ListNode * c = new ListNode(1);
    a->next = b;
    b->next = c;
    c->next = a;

}
