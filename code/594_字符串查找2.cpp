#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;

int strStr2(const char* source, const char* target) {
    if (!source || !target) return -1;
    if (strlen(source) == 0 && strlen(target) == 0) return 0;
    if (strlen(source) && !strlen(target)) return 0;
    string s(source);
    string t(target);
    cout << t << endl;
    int n = s.length();
    int m = t.length();
    for (int i = 0;i < n - m + 1;i++) {
        if (s[i] == t[0] && s[i+m-1] == t[m-1]) {
            if (s.substr(i,m) == t) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    string source = "aaab";
    string target = "ab";
    cout << strStr2(source.c_str(),target.c_str()) << endl;
    return 0;
}
