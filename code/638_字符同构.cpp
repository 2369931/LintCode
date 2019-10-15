#include <iostream>
#include <string>
#include <map>

using namespace std;

bool isIsomorphic(string &s, string &t) {
    int n = s.length();
    int m = t.length();
    if (n != m) {
        return false;
    }
    map<char,char> record_1;
    map<char,char> record_2;
    int result_1 = true;
    int result_2 = true;
    for (int i = 0;i < n;i++) {
        map<char,char>::iterator it = record_1.find(s[i]);
        if (it == record_1.end()) {
            record_1[s[i]] = t[i];
        }
        else {
            if (record_1[s[i]] != t[i]) {
                result_1 = false;
            }
        }
    }
    for (int i = 0;i < n;i++) {
        map<char,char>::iterator it = record_2.find(t[i]);
        if (it == record_2.end()) {
            record_2[t[i]] = s[i];
        }
        else {
            if (record_2[t[i]] != s[i]) {
                result_2 = false;
            }
        }
    }
    return result_1 && result_2;
}

int main() {
    string a = "paper";
    string b = "title";
    cout << isIsomorphic(a,b) << endl;
    cout << endl << endl;
    return 0;
}
