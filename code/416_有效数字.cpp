#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

bool judge(char a) {
    if (a >= '0' && a <= '9') {
        return true;
    }
    else {
        return false;
    }
}

bool isNumber(string &s) {
    int n = s.length();
    if (n == 0) {
        return false;
    }
    if (n == 1) {
        if (judge(s[0])) {
            return true;
        }
        else {
            return false;
        }
    }
    int start = 0;
    int end = n - 1;
    int number = 0;
    for (int i = 0;i < n;i++) {
        if (judge(s[i])) {
            number ++;
        }
    }
    if (number == 0) {
        return false;
    }
    while (start < end) {
        if (s[start] == ' ' || s[start] == '-' || s[start] == '+' || s[start] == '.') {
            start ++;
        }
        else if (judge(s[start])) {
            break;
        }
        else {
            return false;
        }
    }
    while (start < end) {
        if (s[end] == ' ' || s[end] == '.') {
            end --;
        }
        else if (judge(s[end])) {
            break;
        }
        else {
            return false;
        }
    }
    //cout << start << " : " << end << endl;
    int flag_1 = 0;
    int flag_e = 0;
    for (int i = start;i <= end;i++) {
        if (s[i] == '.' && flag_1 == 0) {
            flag_1 = 1;
            continue;
        }
        else if (s[i] == 'e' && flag_1 == 0) {
            flag_e = 1;
            continue;
        }
        else if (judge(s[i])) {
            continue;
        }
        else {
            return false;
        }
    }
    return true;
    //return false;
}

int main() {
    string test = " .";
    cout << isNumber(test) << endl;
    return 0;
}
