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

ListNode * swapPairs(ListNode * head) {
    if (head == NULL) {
        return head;
    }
    ListNode * node = head;
    int num = 0;
    while (node->next != NULL) {
        if (num%2 == 0) {
            int temp = node->val;
            node->val = node->next->val;
            node->next->val = temp;
        }
        num ++;
        node = node->next;
    }
    return head;
}
