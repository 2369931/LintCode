#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <stdlib.h>

using namespace std;

int evalRPN(vector<string> &tokens) {
    int n = tokens.size();
    if (n == 0) {
        return 0;
    }
    stack<int> temp;
    int a = 0;
    int b = 0;
    int c = 0;
    for (int i = 0;i < n;i++) {
        if (tokens[i] == "+") {
            b = temp.top();
            temp.pop();
            a = temp.top();
            temp.pop();
            c = a + b;
            temp.push(c);
        }
        else if (tokens[i] == "-") {
            b = temp.top();
            temp.pop();
            a = temp.top();
            temp.pop();
            c = a - b;
            temp.push(c);
        }
        else if (tokens[i] == "*") {
            b = temp.top();
            temp.pop();
            a = temp.top();
            temp.pop();
            c = a * b;
            temp.push(c);
        }
        else if (tokens[i] == "/") {
            b = temp.top();
            temp.pop();
            a = temp.top();
            temp.pop();
            c = a / b;
            temp.push(c);
        }
        else {
            temp.push(atoi(tokens[i].c_str()));
        }
    }
    return temp.top();
}

int main() {
    string a[5] = {"4", "13", "5", "/", "+"};
    vector<string> test(a,a+5);
    cout << evalRPN(test) << endl;
    return 0;
}
