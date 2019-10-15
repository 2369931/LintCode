#include <iostream>
#include <vector>
#include <stdio.h>
#include <sys/time.h>

using namespace std;
int totaltime = 0;
class LFUCache {

public:

int capacity;
struct node {
    int value;
    int number;
    int time;
};
vector<pair<int,struct node> > cache;

LFUCache(int capacity) {
    this->capacity = capacity;
}

void remove_cache(vector<pair<int,struct node> > &cache) {
    int min_number = 9999999;
    int min_time = 9999999;
    int index = -1;
    for (int i = 0;i < cache.size();i ++) {
        if (cache[i].second.number < min_number) {
            min_number = cache[i].second.number;
            min_time = cache[i].second.time;
            index = i;
        }
        else if (cache[i].second.number == min_number) {
            if (cache[i].second.time < min_time) {
                min_number = cache[i].second.number;
                min_time = cache[i].second.time;
                index = i;
            }
        }
    }
    cache.erase(cache.begin()+index);
}

void set(int key, int value) {
    totaltime += 1;
    struct node new_node;
    new_node.value = value;
    new_node.number = 1;
    new_node.time = totaltime;
    pair<int,struct node> p(key,new_node);
    bool find_flag = false;
    int index = -1;
    for (int i = 0;i < cache.size();i++) {
        if (key == cache[i].first) {
            find_flag = true;
            index = i;
            break;
        }
    }
    if (find_flag) {
        cache[index].second.value = value;
        cache[index].second.number += 1;
        cache[index].second.time = totaltime;
        //sort_cache(cache);
        pair<int,struct node> temp = cache[index];
        cache.erase(cache.begin()+index);
        cache.insert(cache.begin(),temp);
    }
    else {
        if (cache.size() < capacity) {
            cache.insert(cache.begin(),p);
        }
        else {
            remove_cache(cache);
            cache.insert(cache.begin(),p);
        }
    }
}

int get(int key) {
    totaltime += 1;
    for (int i = 0;i < cache.size();i ++) {
        if (cache[i].first == key) {
            cache[i].second.number += 1;
            cache[i].second.time = totaltime;
            int result = cache[i].second.value;
            pair<int,struct node> temp = cache[i];
            cache.erase(cache.begin()+i);
            cache.insert(cache.begin(),temp);
            return result;
        }
    }
    return -1;
}

void print() {
    for (int i = 0;i < cache.size();i++) {
        cout << cache[i].first << " ," << cache[i].second.value
        << " ," << cache[i].second.number
        << " ," << cache[i].second.time << endl;
    }
}
};
int main() {
    LFUCache test(3);
    test.set(1,10);
    test.set(2,20);
    test.set(3,30);
    cout << test.get(1) << endl;
    test.print();
    test.set(4,40);
    cout << test.get(4) << endl;
    cout << test.get(3) << endl;
    cout << test.get(2) << endl;
    cout << test.get(1) << endl;
    test.set(5,50);
    cout << test.get(1) << endl;
    cout << test.get(2) << endl;
    cout << test.get(3) << endl;
    cout << test.get(4) << endl;
    cout << test.get(5) << endl;
    //test.print();
    /*test.set(2,2);
    test.set(1,1);
    cout << test.get(2) << endl;
    cout << test.get(1) << endl;
    cout << test.get(2) << endl;
    test.set(3,3);
    test.set(4,4);
    cout << test.get(3) << endl;
    cout << test.get(2) << endl;
    cout << test.get(1) << endl;
    cout << test.get(4) << endl;*/
    return 0;
}
