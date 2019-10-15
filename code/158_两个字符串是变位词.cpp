#include <iostream>
#include <string>
#include <map>

using namespace std;

bool anagram(string &s, string &t) {
    if (s.length() != t.length()) return false;
    map<char,int> record_s;
    map<char,int> record_t;
    for (int i = 0;i < s.length();i++) {
        record_s[s[i]] += 1;
    }
    for (int i = 0;i < t.length();i++) {
        record_t[t[i]] += 1;
    }
    if (record_s.size() != record_t.size()) return false;
    map<char,int>::iterator it;
    for (it = record_s.begin();it != record_s.end();it++) {
        if (it->second != record_t[it->first])
            return false;
    }
    return true;
}

int main() {
    string s = "aacc";
    string t = "ccac";
    cout << anagram(s, t) << endl;
    return 0;
}

