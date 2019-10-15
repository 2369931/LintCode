#include <iostream>
#include <stack>

using namespace std;

void addToBottom(stack<int>& s, int t) {
    if (s.empty()) {
        s.push(t);
    }
    else {
        int temp = s.top();
        s.pop();
        addToBottom(s, t);
        s.push(temp);
    }
}

void change(stack<int>& s) {
    /*if (s.empty()) {
        return;
    }*/
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        change(s);
        addToBottom(s, temp);
    }
}

int main() {
    stack<int> s;
    for (int i = 0;i < 5;i ++) {
        s.push(i);
    }
    change(s);
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}
