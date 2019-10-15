#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string spilt(string str, int i, int j) {
    string res = "";
    for (int k = i;k <= j;k ++) {
        res += str[k];
    }
    return res;
}

void change(string& str) {
    for (int i = 0;i < str.length();i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'a' + str[i] - 'A';
        }
    }
}

void dp(string& s, unordered_set<string>& dict, int pos, int& res) {
    if(pos == s.length()) {
        res ++;
        return;
    }
    string str;
    for (int j = pos; j < s.length();j ++) {
        str = spilt(s, pos, j);
        if (dict.find(str) != dict.end()) {
            dp(s, dict, j+1, res);
        }
    }
}

int wordBreak3(string& s, unordered_set<string>& dict) {
    int n = s.length();
    int m = dict.size();
    if (n == 0 || m == 0) {
        return 0;
    }
    change(s);
    unordered_set<string> dict_new;
    for (unordered_set<string>::iterator it = dict.begin();it != dict.end();it++) {
        string str = *it;
        change(str);
        dict_new.insert(str);
    }
    int num = 0;
    dp(s, dict_new, 0, num);
    return num;
}

int main() {
    string a = "ASSSDaaa";
    change(a);
    cout << a << endl;
    return 0;
}
