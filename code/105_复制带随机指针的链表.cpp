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

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode *copyRandomList(RandomListNode *head) {
    struct RandomListNode * result = new struct RandomListNode(0);
    struct RandomListNode * p = result;
    while (head != NULL) {
        struct RandomListNode * temp = new struct RandomListNode(head->label);
        temp->next = head->next;
        temp->random = head->random;
        p->next = temp;
        p = p->next;
        head = head->next;
    }
    return result->next;
}
