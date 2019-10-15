#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool judge(string &s, string &l) {
    if (s.length() != l.length()) return false;
    sort(s.begin(),s.end());
    sort(l.begin(),l.end());
    if (s == l)
        return true;
    else
        return false;
}
///94% time limit
vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    int n = strs.size();
    vector<int> record(n,0);
    for (int i = 0;i < n;i++) {
        if (record[i] == 0) {
            result.push_back(strs[i]);
            record[i] = 1;
            int flag = 0;
            for (int j = i+1;j < n;j++) {
                if (record[j] == 0) {
                    if (judge(strs[i],strs[j])) {
                        record[j] = 1;
                        result.push_back(strs[j]);
                        flag = 1;
                    }
                }
            }
            if (flag == 0) {
                result.pop_back();
                record[i] = 0;
            }
        }
    }
    return result;
}

vector<string> anagrams(vector<string> &strs) {
    vector<string> result;
    int n = strs.size();
    map<string,int> record;
    for (int i = 0;i < n;i++) {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        record[temp] ++;
    }
    for (int i = 0;i < n;i++) {
        string temp = strs[i];
        sort(temp.begin(),temp.end());
        if (record[temp] > 1) {
            result.push_back(strs[i]);
        }
    }
    return result;
}

int main() {
    string a = "abcd";
    string b = "acbd";
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    cout << a << " " << b << endl;

    cout << judge(a,b) << endl;
    return 0;
}
