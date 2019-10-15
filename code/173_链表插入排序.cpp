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

ListNode * insertionSortList(ListNode * head) {
    if (head == NULL) return NULL;
    ListNode * result = new ListNode(INT_MIN);
    ListNode * temp = head;
    while (temp != NULL) {
        ListNode * result_temp = result;
        while (result_temp != NULL) {
            if (temp->val >= result_temp->val) {
                if (result_temp->next == NULL) {
                    ListNode * node = new ListNode(temp->val);
                    result_temp->next = node;
                    break;
                }
                else if (result_temp->next != NULL && result_temp->next->val >= temp->val) {
                    ListNode * node = new ListNode(temp->val);
                    ListNode * record = result_temp->next;
                    result_temp->next = node;
                    node->next = record;;
                    break;
                }
            }
            result_temp = result_temp->next;
        }
        temp = temp->next;
    }
    return result->next;
}

int main() {
}
