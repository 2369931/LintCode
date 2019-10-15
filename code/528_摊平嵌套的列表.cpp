#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

class NestedInteger {
  public:
    // Return true if this NestedInteger holds a single integer,
    // rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds,
    // if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds,
    // if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:
    queue<int> v;
    NestedIterator(vector<NestedInteger> &nestedList) {
        // Initialize your data structure here.
        process(nestedList, v);
    }

    void process(const vector<NestedInteger> &nestedList, queue<int> &v) {
        int length = nestedList.size();
        if (length == 0) {
            return;
        }
        for (int i = 0;i < length;i++) {
            if (nestedList[i].isInteger()) {
                v.push(nestedList[i].getInteger());
            }
            else {
                process(nestedList[i].getList(),v);
            }
        }
    }

    // @return {int} the next element in the iteration
    int next() {
        // Write your code here
        int temp = v.front();
        v.pop();
        return temp;
    }

    // @return {boolean} true if the iteration has more element or false
    bool hasNext() {
        // Write your code here
        if (!v.empty())
            return true;
        else
            return false;
    }
};
