#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
public:

stack<int> stack_a;
stack<int> stack_b;

MyQueue() {
}

void push(int element) {
    stack_a.push(element);
}

int pop() {
    if (!stack_b.empty()) {
        int result = stack_b.top();
        stack_b.pop();
        return result;
    }
    else {
        int n = stack_a.size();
        for (int i = 0;i < n - 1;i++) {
            int temp = stack_a.top();
            stack_a.pop();
            stack_b.push(temp);
        }
        int result = stack_a.top();
        stack_a.pop();
        return result;
    }
}

int top() {
    if (!stack_b.empty()) {
        return stack_b.top();
    }
    else {
        int temp = 0;
        int n = stack_a.size();
        for (int i = 0;i < n;i++) {
            temp = stack_a.top();
            stack_a.pop();
            stack_b.push(temp);
        }
        return temp;
    }
}
};

int main() {
    MyQueue test;
    test.push(1);
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    cout << test.pop() << endl;
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    test.push(2);
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    test.push(3);
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    cout << test.top() << endl;
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    cout << test.pop() << endl;
    //cout << test.stack_a.size() << ":" << test.stack_b.size() << endl;
    return 0;
}
