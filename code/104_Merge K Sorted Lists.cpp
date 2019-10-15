#include <iostream>
#include <limits>

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

ListNode *mergeKLists(vector<ListNode *> &lists) {
    int n = lists.size();
    if (n == 0) return NULL;
    if (n == 1) return lists[0];
    vector<ListNode *> record;
    int length = 0;
    for (int i = 0;i < n;i++) {
        ListNode * temp = lists[i];
        if (temp == NULL) {
            length ++;
        }
        record.push_back(temp);
    }
    ListNode * result = new ListNode(0);
    ListNode * p = result;
    while (length < n) {
        int value = INT_MAX;
        int index = -1;
        for (int i = 0;i < n;i++) {
            if (record[i] == NULL) continue;
            else if (value > record[i]->val) {
                value = record[i]->val;
                index = i;
            }
        }
        if (index != -1) {
            ListNode * temp = new ListNode(value);
            p->next = temp;
            p = p->next;
            record[index] = record[index]->next;
            if (record[index] == NULL) length++;
        }
    }
    return result->next;
}
