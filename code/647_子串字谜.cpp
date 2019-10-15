#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool judge(map<char,int> source,map<char,int> target) {
    int flag = 0;
    for (map<char,int>::iterator it = source.begin();it != source.end();it++) {
        map<char,int>::iterator itt = target.find(it->first);
        if (itt == target.end() || itt->second != it->second) {
            flag = 1;
            break;
        }
    }
    if (flag == 0) {
       return true;
    }
    else {
        return false;
    }
}

vector<int> findAnagrams(string &s, string &p) {
    vector<int> res;
    int n = s.length();
    int m = p.length();
    if (n == 0) {
        return res;
    }
    map<char,int> source;
    map<char,int> target;
    for (int i = 0;i < m;i++) {
        map<char,int>::iterator it = source.find(p[i]);
        if (it == source.end()) {
            source[p[i]] = 1;
        }
        else {
            source[p[i]] += 1;
        }
    }
    string str = s.substr(0,m);
    for (int i = 0;i < m;i++) {
        map<char,int>::iterator it = target.find(str[i]);
        if (it == target.end()) {
            target[str[i]] = 1;
        }
        else {
            target[str[i]] += 1;
        }
    }
    if (judge(source,target)) {
        res.push_back(0);
    }
    for (int i = 0;i < n - m;i ++) {
        target[s[i]] --;
        if (target[s[i]] == 0) {
            target.erase(s[i]);
        }
        map<char,int>::iterator add = target.find(s[i+m]);
        if (add == target.end()) {
            target[s[i+m]] = 1;
        }
        else {
            target[s[i+m]] += 1;
        }
        if (judge(source,target)) {
            res.push_back(i+1);
        }
    }
    return res;
}

int main() {
    string s1 = "cbaebabacd";
    string s2 = "abc";
    vector<int> res = findAnagrams(s1,s2);
    for (int i = 0;i < res.size();i++) {
        cout << res[i] << " ";
    }
    return 0;
}
