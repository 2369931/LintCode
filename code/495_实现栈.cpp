#include <iostream>
#include <vector>

using namespace std;

class Stack {
public:
    vector<int> sta;
    void push(int x) {
        sta.push_back(x);
    }

    void pop() {
       sta.pop_back();
    }

    int top() {
       return sta.back();
    }

    bool isEmpty() {
       return (sta.size() == 0);
    }
};
