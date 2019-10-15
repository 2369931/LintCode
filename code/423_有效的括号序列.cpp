#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValidParentheses(string &s) {
    int n = s.length();
    if (n == 0) {
        return true;
    }
    stack<char> temp;
    for (int i = 0;i < n;i++) {
        if (s[i] == ' ')
            continue;
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            temp.push(s[i]);
        }
        else {
            if (s[i] == ')') {
                if (!temp.empty() && temp.top() == '(') {
                        temp.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == ']') {
                if (!temp.empty() && temp.top() == '[') {
                        temp.pop();
                }
                else {
                    return false;
                }
            }
            else if (s[i] == '}') {
                if (!temp.empty() && temp.top() == '{') {
                        temp.pop();
                }
                else {
                    return false;
                }
            }
        }
    }
    if (temp.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main () {
    string test = "]";
    cout << isValidParentheses(test) << endl;
    return 0;
}
