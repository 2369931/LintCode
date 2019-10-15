#include <iostream>
#include <ctime>

using namespace std;

class RandomizedSet {
public:

    map<int,int> record;
    vector<int> temp;

    RandomizedSet() {
        // do intialization if necessary
    }

    bool insert(int val) {
        if (record.count(val)) {
            return false;
        }
        temp.push_back(val);
        record[val] = temp.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (!record.count(val)) {
            return false;
        }
        int last = temp.back();
        record[last] = record[val];
        temp[record[val]] = last;
        temp.pop_back();
        record.erase(val);
        return true;
    }

    int getRandom() {
        // write your code here
        return temp[rand()%(temp.size())];
    }
};
