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

ListNode * middle(ListNode * head) {
    if (head == NULL) return NULL;
    ListNode * slow = head;
    ListNode * fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode * reverse(ListNode * head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * result = NULL;
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

void reorderList(ListNode * head) {
    if (head == NULL) return;
    ListNode * mid = middle(head);
    ListNode * reverse_mid = reverse(mid->next);
    mid->next = NULL;
    ListNode * p = head;
    while (reverse_mid != NULL) {
        ListNode * insert_node = new ListNode(reverse_mid->val);
        ListNode * temp = p->next;
        if (temp == NULL) {
            p->next = reverse_mid;
            return;
        }
        p->next = insert_node;
        insert_node->next = temp;
        p = temp;
        reverse_mid = reverse_mid->next;
    }
}

int main() {
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    ListNode * c = new ListNode(3);
    a->next = b;
    b->next = c;
    /*ListNode * result = */reorderList(a);
    while (a != NULL) {
        cout << a->val << " ";
        a = a->next;
    }
    return 0;
}
