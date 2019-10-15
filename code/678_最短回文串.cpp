#include <iostream>
#include <string>

using namespace std;

bool judge (string s, int low, int high) {
    if (low == high) {
        return true;
    }
    while (low < high) {
        if (s[low] != s[high]) {
            return false;
        }
        low ++;
        high --;
    }
    return true;
}

string convertPalindrome(string &str) {
    int len = str.length();
    string res = "";
    if (len <= 0) {
        return "";
    }
    for (len;len > 0;len--) {
        if (str[0] == str[len] && judge(str,0,len))
            break;
    }
    for (int i = str.length() - 1;i > len;i--) {
        res += str[i];
    }
    res += str;
    return res;
}

int main() {
    return 0;
}
