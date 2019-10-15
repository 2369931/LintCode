#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>
#include <stdio.h>

using namespace std;

bool judge (char s) {
    if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z') || (s >= '0' && s <= '9')) {
        return true;
    }
    else {
        return false;
    }
}

bool equal_s(char a, char b) {
    if (a == b) {
        return true;
    }
    else {
        if (a >= 'A' && a <= 'Z') {
            a = a + 32;
        }
        if (b >= 'A' && b <= 'Z') {
            b = b + 32;
        }
        if (a == b) {
            return true;
        }
    }
    return false;
}

bool isPalindrome(string &s) {
    int n = s.length();
    if (n == 0) {
        return true;
    }
    if (n == 1) {
        /*if (judge(s[0])) {
            return true;
        }
        else {
            return false;
        }*/
        return true;
    }
    int start = 0;
    int end = n - 1;
    while (start < end) {

        if (!judge(s[start])) {
            start ++;
        }
        else if (!judge(s[end])) {
            end --;
        }
        else if (judge(s[start]) && judge(s[end])) {
            if (!equal_s(s[start],s[end])) {
                return false;
            }
            start ++;
            end --;
        }
    }
    return true;
}

int main(){
    string test = "A man, a plan, a canal: Panama";
    cout << isPalindrome(test) << endl;
    return 0;
}
