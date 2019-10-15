#include <iostream>
#include <cmath>
#include <limits>
#include <vector>

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

ListNode * deleteDuplicates(ListNode * head) {
    if (head == NULL || head->next == NULL) return head;
    ListNode * temp = head;
    ListNode * temp_next = temp->next;
    while (temp_next != NULL) {
        int value = temp->val;
        int temp_value = temp_next->val;
        if (value == temp_value) {
            temp->next = temp_next->next;
            temp_next = temp_next->next;
        }
        else {
            temp = temp_next;
            temp_next = temp_next->next;
        }
    }
    return head;
}

int main() {
    return 0;
}
