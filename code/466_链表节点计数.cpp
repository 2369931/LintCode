#include <iostream>
#include <vector>
#include <map>
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
}

int countNodes(ListNode * head) {
    if (head == NULL) {
        return 0;
    }
    int result = 0;
    while (head != NULL) {
        head = head->next;
        result += 1;
    }
    return result;
}
