#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <limits>
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

void deleteNode(ListNode * node) {
    if (node == NULL) return;
    ListNode * record = node;
    while (node->next != NULL) {
        node->val = node->next->val;
        record = node;
        node = node->next;
    }
    record->next = NULL;
}
