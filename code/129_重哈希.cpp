#include <iostream>
#include <cmath>
#include <limits>
#include <vector>
#include <string>
#include <map>

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

void insert(vector<ListNode*> &hashTable, int i, int val) {
    ListNode * temp = new ListNode(val);
    if (hashTable[i] == NULL) hashTable[i] = temp;
    else {
        ListNode * p = hashTable[i];
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
    vector<ListNode*> result;
    int n = hashTable.size();
    int m = 2*n;
    if (n == 0) return result;
    for (int i = 0;i < m;i++) {
        result.push_back(NULL);
    }
    for (int i = 0;i < n;i++) {
        ListNode * temp = hashTable[i];
        if (temp != NULL) {
            while (temp != NULL) {
                int val = temp->val;
                int index = (val % m + m) % m;
                insert(result,index,val);
                temp = temp->next;
            }
        }
    }
    return result;
}
