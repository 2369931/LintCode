#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>

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

ListNode * reverse(ListNode * l1) {
    if (l1 == NULL || l1->next == NULL) {
        return l1;
    }
    ListNode * p = l1;
    ListNode * q = l1->next;
    l1->next = NULL;
    while (q != NULL){
        ListNode * temp = q->next;
        q->next = p;
        p = q;
        q = temp;
    }
    return p;
}

void print(ListNode * head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

bool isPalindrome(ListNode * head) {
    if (head == NULL || head->next == NULL) return true;
    ListNode * copy_head_t = new ListNode(0);
    ListNode * temp = head;
    ListNode * copy_head = copy_head_t;
    while (head != NULL) {
        ListNode * node = new ListNode(head->val);
        copy_head->next = node;
        head = head->next;
        copy_head = copy_head->next;
    }
    head = reverse(temp);
    copy_head_t = copy_head_t->next;
    print(head);
    print(copy_head_t);
    while (head != NULL) {
        if (head->val != copy_head_t->val) {
            return false;
        }
        head = head->next;
        copy_head_t = copy_head_t->next;
    }
    return true;
}


int main() {
    ListNode * a = new ListNode(0);
    ListNode * b = new ListNode(1);
    ListNode * c = new ListNode(2);
    ListNode * d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    isPalindrome(a);
    return 0;
}

