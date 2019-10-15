#include <iostream>
#include <string>
#include <map>

using namespace std;

string concatenetedString(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    if (n == 0) {
        return s2;
    }
    if (m == 0) {
        return s1;
    }
    map<char, int> record_s1;
    map<char, int> record_s2;
    for (int i = 0;i < n;i++) {
        map<char,int>::iterator it = record_s1.find(s1[i]);
        if (it == record_s1.end()) {
            record_s1[s1[i]] = 1;
        }
    }
    for (int i = 0;i < m;i++) {
        map<char,int>::iterator it = record_s2.find(s2[i]);
        if (it == record_s2.end()) {
            record_s2[s2[i]] = 1;
        }
    }
    string res = "";
    for (int i = 0;i < n;i++) {
        map<char,int>::iterator it = record_s2.find(s1[i]);
        if (it == record_s2.end()) {
            res += s1[i];
        }
    }
    for (int i = 0;i < m;i++) {
        map<char,int>::iterator it = record_s1.find(s2[i]);
        if (it == record_s1.end()) {
            res += s2[i];
        }
    }
    return res;
}

int main() {
    string s1 = "abcs";
    string s2 = "cxzca";
    cout << concatenetedString(s1, s2) << endl;
    return 0;
}
