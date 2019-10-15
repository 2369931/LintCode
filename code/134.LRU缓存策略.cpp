#include <iostream>
#include <string>
#include <vector>
#include <limits>

using namespace std;

class LRUCache {
public:
    int capacity;
    class ListNode {
    public:
        int key;
        int val;
        ListNode *next;
        ListNode(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
        }
    };
    ListNode * cache;
    /*
    * @param capacity: An integer
    */LRUCache(int capacity) {
        this->capacity = capacity;
        cache = NULL;
    }

    /*
     * @param key: An integer
     * @return: An integer
     */
    int get(int key) {
        ListNode * temp = cache;
        if (temp->key == key) {
            return temp->val;
        }
        while (temp->next != NULL) {
            if (temp->next->key == key) {
                int result = temp->next->val;
                ListNode * new_header = new ListNode(key,temp->next->val);
                new_header->next = cache;
                cache = new_header;
                temp->next = temp->next->next;
                return result;
            }
            temp = temp -> next;
        }
        return -1;
    }

    /*
     * @param key: An integer
     * @param value: An integer
     * @return: nothing
     */
    void set(int key, int value) {
        // write your code here
        int length = 0;
        ListNode * temp = cache;
        ListNode * temp_2 = cache;
        int flag = 0;
        while (temp_2 != NULL) {
            length ++;
            temp_2 = temp_2->next;
        }
        if (length != 0) {
            if (temp->key == key) {
                temp->val = value;
                return;
            }
            while (temp->next != NULL) {
                if (temp->next->key == key) {
                    flag = 1;
                    temp->next = temp->next->next;
                    break;
                }
                temp = temp->next;
            }
        }
        ListNode * new_header = new ListNode(key,value);
        new_header->next = cache;
        cache = new_header;
        if ((length+1) > this->capacity && flag == 0) {
            ListNode * tail = cache;
            while (tail->next->next != NULL) {
                tail = tail->next;
            }
            tail->next = NULL;
        }
    }
    void print() {
        ListNode * temp = cache;
        while (temp != NULL) {
            cout << temp->key  << " : " << temp->val << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LRUCache cache(2);
    cache.set(1,1);
    cache.set(2,2);
    cache.print();
    cache.set(1,3);
    /*cache.set(4,4);
    cache.set(5,5);
    cache.set(6,6);
    cache.set(7,7);*/
    cache.print();
    //cout << cache.get(6) << endl;
    //cache.print();
    //cout << cache.get(8) << endl;
    //cache.print();
    //cout << cache.get(1) << endl;
    //cache.print();
    return 0;
}
