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

ListNode * addLists2(ListNode * l1, ListNode * l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;
    l1 = reverse(l1);
    l2 = reverse(l2);
    ListNode * result = new ListNode(0);
    ListNode * head = result;
    int flag = 0;
    while (l1 != NULL || l2 != NULL) {
        int temp = 0;
        if (l1 != NULL && l2 != NULL) {
            temp = l1->val + l2->val + flag;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        else if (l1 == NULL && l2 != NULL) {
            temp = l2->val + flag;
            l2 = l2 -> next;
        }
        else if (l1 != NULL && l2 == NULL) {
            temp = l1->val + flag;
            l1 = l1 -> next;
        }
        if (temp >= 10) {
            temp -= 10;
            flag = 1;
        }
        else {
            flag = 0;
        }
        ListNode * node = new ListNode(temp);
        head -> next = node;
        head = head -> next;
    }
    if (flag == 1) {
        ListNode * node = new ListNode(1);
        head -> next = node;
    }
    return reverse(result->next);
}


int main() {
    ListNode * a = new ListNode(0);
    ListNode * b = new ListNode(1);
    ListNode * c = new ListNode(2);
    ListNode * d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    ListNode * head = reverse(a);
    //print(head);
    ListNode * h = head;
    print(addLists2(head,h));
    return 0;
}
